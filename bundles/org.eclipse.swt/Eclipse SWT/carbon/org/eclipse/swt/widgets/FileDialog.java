/*******************************************************************************
 * Copyright (c) 2000, 2003 IBM Corporation and others.
 * All rights reserved. This program and the accompanying materials 
 * are made available under the terms of the Common Public License v1.0
 * which accompanies this distribution, and is available at
 * http://www.eclipse.org/legal/cpl-v10.html
 * 
 * Contributors:
 *     IBM Corporation - initial API and implementation
 *******************************************************************************/
package org.eclipse.swt.widgets;

 
import org.eclipse.swt.*;
import org.eclipse.swt.internal.carbon.*;

/**
 * Instances of this class allow the user to navigate
 * the file system and select or enter a file name.
 * <dl>
 * <dt><b>Styles:</b></dt>
 * <dd>SAVE, OPEN, MULTI</dd>
 * <dt><b>Events:</b></dt>
 * <dd>(none)</dd>
 * </dl>
 * <p>
 * IMPORTANT: This class is intended to be subclassed <em>only</em>
 * within the SWT implementation.
 * </p>
 */
public class FileDialog extends Dialog {
	String [] filterNames = new String [0];
	String [] filterExtensions = new String [0];
	String [] fileNames = new String[0];	
	String filterPath = "", fileName = "";

/**
 * Constructs a new instance of this class given only its parent.
 *
 * @param parent a shell which will be the parent of the new instance
 *
 * @exception IllegalArgumentException <ul>
 *    <li>ERROR_NULL_ARGUMENT - if the parent is null</li>
 * </ul>
 * @exception SWTException <ul>
 *    <li>ERROR_THREAD_INVALID_ACCESS - if not called from the thread that created the parent</li>
 *    <li>ERROR_INVALID_SUBCLASS - if this class is not an allowed subclass</li>
 * </ul>
 */
public FileDialog (Shell parent) {
	this (parent, SWT.APPLICATION_MODAL);
}

/**
 * Constructs a new instance of this class given its parent
 * and a style value describing its behavior and appearance.
 * <p>
 * The style value is either one of the style constants defined in
 * class <code>SWT</code> which is applicable to instances of this
 * class, or must be built by <em>bitwise OR</em>'ing together 
 * (that is, using the <code>int</code> "|" operator) two or more
 * of those <code>SWT</code> style constants. The class description
 * lists the style constants that are applicable to the class.
 * Style bits are also inherited from superclasses.
 * </p>
 *
 * @param parent a shell which will be the parent of the new instance
 * @param style the style of dialog to construct
 *
 * @exception IllegalArgumentException <ul>
 *    <li>ERROR_NULL_ARGUMENT - if the parent is null</li>
 * </ul>
 * @exception SWTException <ul>
 *    <li>ERROR_THREAD_INVALID_ACCESS - if not called from the thread that created the parent</li>
 *    <li>ERROR_INVALID_SUBCLASS - if this class is not an allowed subclass</li>
 * </ul>
 */
public FileDialog (Shell parent, int style) {
	super (parent, style);
	checkSubclass ();
}

/**
 * Returns the path of the first file that was
 * selected in the dialog relative to the filter path
 * 
 * @return the relative path of the file
 */
public String getFileName () {
	return fileName;
}

/**
 * Returns the paths of all files that were selected
 * in the dialog relative to the filter path.
 * 
 * @return the relative paths of the files
 */
public String [] getFileNames () {
	return fileNames;
}

/**
 * Returns the file extensions which the dialog will
 * use to filter the files it shows.
 *
 * @return the file extensions filter
 */
public String [] getFilterExtensions () {
	return filterExtensions;
}

/**
 * Returns the file names which the dialog will
 * use to filter the files it shows.
 *
 * @return the file name filter
 */
public String [] getFilterNames () {
	return filterNames;
}

/**
 * Returns the directory path that the dialog will use.
 * File names in this path will appear in the dialog,
 * filtered according to the filter extensions.
 *
 * @return the directory path string
 * 
 * @see #setFilterExtensions
 */
public String getFilterPath () {
	return filterPath;
}

/**
 * Makes the dialog visible and brings it to the front
 * of the display.
 *
 * @return a string describing the absolute path of the first selected file,
 *         or null if the dialog was cancelled or an error occurred
 *
 * @exception SWTException <ul>
 *    <li>ERROR_WIDGET_DISPOSED - if the dialog has been disposed</li>
 *    <li>ERROR_THREAD_INVALID_ACCESS - if not called from the thread that created the dialog</li>
 * </ul>
 */
public String open () {
	String fullPath = null;
	fileNames = new String [0];
		
	int titlePtr = 0;
	if (title != null) {
		char [] buffer = new char [title.length ()];
		title.getChars (0, buffer.length, buffer, 0);
		titlePtr = OS.CFStringCreateWithCharacters (OS.kCFAllocatorDefault, buffer, buffer.length);
	}
	int fileNamePtr = 0;
	if (fileName != null) {
		char [] buffer = new char [fileName.length ()];
		fileName.getChars (0, buffer.length, buffer, 0);
		fileNamePtr = OS.CFStringCreateWithCharacters (OS.kCFAllocatorDefault, buffer, buffer.length);		
	}
		
	NavDialogCreationOptions options = new NavDialogCreationOptions ();
	options.windowTitle = options.clientName = titlePtr;
	options.parentWindow = OS.GetControlOwner (parent.handle);
	options.optionFlags = OS.kNavSupportPackages | OS.kNavAllowInvisibleFiles;
	options.location_h = -1;
	options.location_v = -1;
	options.saveFileName = fileNamePtr;

	int [] outDialog = new int [1];
	if ((style & SWT.SAVE) != 0) {
		// NEEDS WORK - filter extensions, start in filter path, allow user
		// to select existing files.
		OS.NavCreatePutFileDialog (options, 0, 0, 0, 0, outDialog);		
	} else {
		if ((style & SWT.MULTI) != 0) options.optionFlags |= OS.kNavAllowMultipleFiles;
		// NEEDS WORK - filter extensions, start in filter path, select file name if it exists
		OS.NavCreateGetFileDialog(options, 0, 0, 0, 0, 0, outDialog);
	}
	if (outDialog [0] != 0) {
		OS.NavDialogRun (outDialog [0]);
		int action = OS.NavDialogGetUserAction (outDialog [0]);
		switch (action) {
			case OS.kNavUserActionOpen:
			case OS.kNavUserActionChoose:							
			case OS.kNavUserActionSaveAs: {
				NavReplyRecord record = new NavReplyRecord ();
				OS.NavDialogGetReply (outDialog [0], record);
				AEDesc selection = new AEDesc ();
				selection.descriptorType = record.selection_descriptorType;
				selection.dataHandle = record.selection_dataHandle;
				int [] count = new int [1];
				OS.AECountItems (selection, count);
				if (count [0] > 0) {
					fileNames = new String [count [0]];
					int maximumSize = 80; // size of FSRef
					int dataPtr = OS.NewPtr (maximumSize);
					int[] aeKeyword = new int [1];
					int[] typeCode = new int [1];
					int[] actualSize = new int [1];
					int pathString = 0;
					int fullString = 0;
					int fileString = 0;
												
					if ((style & SWT.SAVE) != 0) {
						if (OS.AEGetNthPtr (selection, 1, OS.typeFSRef, aeKeyword, typeCode, dataPtr, maximumSize, actualSize) == OS.noErr) {
							byte[] fsRef = new byte[actualSize[0]];
							OS.memcpy (fsRef, dataPtr, actualSize [0]);
							int pathUrl = OS.CFURLCreateFromFSRef (OS.kCFAllocatorDefault, fsRef);
							int fullUrl = OS.CFURLCreateCopyAppendingPathComponent(OS.kCFAllocatorDefault, pathUrl, record.saveFileName, false);
							pathString = OS.CFURLCopyFileSystemPath(pathUrl, OS.kCFURLPOSIXPathStyle);
							fullString = OS.CFURLCopyFileSystemPath(fullUrl, OS.kCFURLPOSIXPathStyle);
							fileString = record.saveFileName;
							OS.CFRelease (pathUrl);
							OS.CFRelease (fullUrl);
						}
					} else {
						for (int i = 0; i < count [0]; i++) {
							if (OS.AEGetNthPtr (selection, i+1, OS.typeFSRef, aeKeyword, typeCode, dataPtr, maximumSize, actualSize) == OS.noErr) {
								byte[] fsRef = new byte[actualSize[0]];
								OS.memcpy (fsRef, dataPtr, actualSize [0]);
								int url = OS.CFURLCreateFromFSRef (OS.kCFAllocatorDefault, fsRef);
								if (i == 0) {
									int pathUrl = OS.CFURLCreateCopyDeletingLastPathComponent(OS.kCFAllocatorDefault, url);
									pathString = OS.CFURLCopyFileSystemPath (pathUrl, OS.kCFURLPOSIXPathStyle);
									fullString = OS.CFURLCopyFileSystemPath (url, OS.kCFURLPOSIXPathStyle);
									fileString = OS.CFURLCopyLastPathComponent (url);
									OS.CFRelease (pathUrl);
								} else {
									int lastString = OS.CFURLCopyLastPathComponent (url);
									int length = OS.CFStringGetLength (lastString);
									char [] buffer= new char [length];
									CFRange range = new CFRange ();
									range.length = length;
									OS.CFStringGetCharacters (lastString, range, buffer);
									fileNames [i] = new String (buffer);
									OS.CFRelease (lastString);
								}
								OS.CFRelease (url);
							}
						}
					}
					OS.DisposePtr (dataPtr);
					
					if (pathString != 0) {		
						int length = OS.CFStringGetLength (pathString);
						char [] buffer= new char [length];
						CFRange range = new CFRange ();
						range.length = length;
						OS.CFStringGetCharacters (pathString, range, buffer);
						OS.CFRelease (pathString);
						filterPath = new String (buffer);
					}
					if (fullString != 0) {
						int length = OS.CFStringGetLength (fullString);
						char [] buffer= new char [length];
						CFRange range = new CFRange ();
						range.length = length;
						OS.CFStringGetCharacters (fullString, range, buffer);
						OS.CFRelease (fullString);
						fullPath = new String (buffer);
					} 
					if (fileString != 0) {
						int length = OS.CFStringGetLength (fileString);
						char [] buffer= new char [length];
						CFRange range = new CFRange ();
						range.length = length;
						OS.CFStringGetCharacters (fileString, range, buffer);
						OS.CFRelease (fileString);
						fileName = fileNames [0] = new String (buffer);
					}
				}
			}
		}
	}

	if (titlePtr != 0) OS.CFRelease (titlePtr);
	if (fileNamePtr != 0) OS.CFRelease (fileNamePtr);	
	if (outDialog [0] != 0) OS.NavDialogDispose (outDialog [0]);

	return fullPath;	
}

/**
 * Set the initial filename which the dialog will
 * select by default when opened to the argument,
 * which may be null.  The name will be prefixed with
 * the filter path when one is supplied.
 * 
 * @param string the file name
 */
public void setFileName (String string) {
	fileName = string;
}

/**
 * Set the file extensions which the dialog will
 * use to filter the files it shows to the argument,
 * which may be null.
 *
 * @param extensions the file extension filter
 */
public void setFilterExtensions (String [] extensions) {
	filterExtensions = extensions;
}

/**
 * Sets the file names which the dialog will
 * use to filter the files it shows to the argument,
 * which may be null.
 *
 * @param names the file name filter
 */
public void setFilterNames (String [] names) {
	filterNames = names;
}

/**
 * Sets the directory path that the dialog will use
 * to the argument, which may be null. File names in this
 * path will appear in the dialog, filtered according
 * to the filter extensions.
 *
 * @param string the directory path
 * 
 * @see #setFilterExtensions
 */
public void setFilterPath (String string) {
	filterPath = string;
}
}
