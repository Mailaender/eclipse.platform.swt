/*******************************************************************************
 * Copyright (c) 2000, 2004 IBM Corporation and others.
 * All rights reserved. This program and the accompanying materials
 * are made available under the terms of the Common Public License v1.0
 * which accompanies this distribution, and is available at
 * http://www.eclipse.org/legal/cpl-v10.html
 * 
 * Contributors:
 *     IBM Corporation - initial API and implementation
 *******************************************************************************/

#ifdef NATIVE_STATS
int OS_nativeFunctionCallCount[];
char* OS_nativeFunctionNames[];
#define OS_NATIVE_ENTER(env, that, func) OS_nativeFunctionCallCount[func]++;
#define OS_NATIVE_EXIT(env, that, func) 
#else
#define OS_NATIVE_ENTER(env, that, func) 
#define OS_NATIVE_EXIT(env, that, func) 
#endif

#define PfDecomposeStemToID_FUNC 0
#define PfExtentText__Lorg_eclipse_swt_internal_photon_PhRect_1t_2Lorg_eclipse_swt_internal_photon_PhPoint_1t_2III_FUNC 1
#define PfExtentText__Lorg_eclipse_swt_internal_photon_PhRect_1t_2Lorg_eclipse_swt_internal_photon_PhPoint_1t_2_3B_3BI_FUNC 2
#define PfExtentWideText_FUNC 3
#define PfFontDescription_FUNC 4
#define PfFontFlags_FUNC 5
#define PfFontSize_FUNC 6
#define PfFreeFont_FUNC 7
#define PfGenerateFontName_FUNC 8
#define PfLoadMetrics_FUNC 9
#define PfQueryFontInfo_FUNC 10
#define PfQueryFonts_FUNC 11
#define PgAlphaOff_FUNC 12
#define PgAlphaOn_FUNC 13
#define PgCreateGC_FUNC 14
#define PgDestroyGC_FUNC 15
#define PgDrawArc_FUNC 16
#define PgDrawArrow_FUNC 17
#define PgDrawBitmap_FUNC 18
#define PgDrawEllipse_FUNC 19
#define PgDrawGradient_FUNC 20
#define PgDrawILine_FUNC 21
#define PgDrawIPixel_FUNC 22
#define PgDrawIRect_FUNC 23
#define PgDrawImage_FUNC 24
#define PgDrawMultiTextArea_FUNC 25
#define PgDrawPhImageRectmx_FUNC 26
#define PgDrawPolygon_FUNC 27
#define PgDrawRoundRect_FUNC 28
#define PgDrawTImage_FUNC 29
#define PgDrawText_FUNC 30
#define PgExtentMultiText_FUNC 31
#define PgFlush_FUNC 32
#define PgGetVideoMode_FUNC 33
#define PgGetVideoModeInfo_FUNC 34
#define PgReadScreen_FUNC 35
#define PgReadScreenSize_FUNC 36
#define PgSetAlpha_FUNC 37
#define PgSetClipping_FUNC 38
#define PgSetDrawBufferSize_FUNC 39
#define PgSetDrawMode_FUNC 40
#define PgSetFillColor_FUNC 41
#define PgSetFillTransPat_FUNC 42
#define PgSetFont_FUNC 43
#define PgSetGC_FUNC 44
#define PgSetMultiClip_FUNC 45
#define PgSetPalette_FUNC 46
#define PgSetRegion_FUNC 47
#define PgSetStrokeCap_FUNC 48
#define PgSetStrokeColor_FUNC 49
#define PgSetStrokeDash_FUNC 50
#define PgSetStrokeWidth_FUNC 51
#define PgSetTextColor_FUNC 52
#define PgSetTextXORColor_FUNC 53
#define PgSetUserClip_FUNC 54
#define PgShmemCreate_FUNC 55
#define PgShmemDestroy_FUNC 56
#define PhAddMergeTiles_FUNC 57
#define PhAreaToRect_FUNC 58
#define PhBlit_FUNC 59
#define PhClipTilings_FUNC 60
#define PhClipboardCopy_FUNC 61
#define PhClipboardCopyString_FUNC 62
#define PhClipboardPasteFinish_FUNC 63
#define PhClipboardPasteStart_FUNC 64
#define PhClipboardPasteString_FUNC 65
#define PhClipboardPasteType_FUNC 66
#define PhClipboardPasteTypeN_FUNC 67
#define PhCoalesceTiles_FUNC 68
#define PhCopyTiles_FUNC 69
#define PhCreateImage_FUNC 70
#define PhDCSetCurrent_FUNC 71
#define PhDeTranslateTiles_FUNC 72
#define PhEventNext_FUNC 73
#define PhEventPeek_FUNC 74
#define PhFreeTiles_FUNC 75
#define PhGetData_FUNC 76
#define PhGetMsgSize_FUNC 77
#define PhGetRects_FUNC 78
#define PhGetTile_FUNC 79
#define PhInitDrag_FUNC 80
#define PhInputGroup_FUNC 81
#define PhIntersectTilings_FUNC 82
#define PhKeyToMb_FUNC 83
#define PhMakeGhostBitmap_FUNC 84
#define PhMakeTransBitmap_FUNC 85
#define PhMergeTiles_FUNC 86
#define PhMoveCursorAbs_FUNC 87
#define PhQueryCursor_FUNC 88
#define PhQueryRids_FUNC 89
#define PhRectIntersect_FUNC 90
#define PhRectUnion__II_FUNC 91
#define PhRectUnion__Lorg_eclipse_swt_internal_photon_PhRect_1t_2Lorg_eclipse_swt_internal_photon_PhRect_1t_2_FUNC 92
#define PhRectsToTiles_FUNC 93
#define PhRegionQuery_FUNC 94
#define PhReleaseImage_FUNC 95
#define PhSortTiles_FUNC 96
#define PhTilesToRects_FUNC 97
#define PhTranslateTiles_FUNC 98
#define PhWindowQueryVisible_FUNC 99
#define PiCropImage_FUNC 100
#define PiDuplicateImage_FUNC 101
#define PmMemCreateMC_FUNC 102
#define PmMemFlush_FUNC 103
#define PmMemReleaseMC_FUNC 104
#define PmMemStart_FUNC 105
#define PmMemStop_FUNC 106
#define PtAddCallback_FUNC 107
#define PtAddEventHandler_FUNC 108
#define PtAddFilterCallback_FUNC 109
#define PtAddHotkeyHandler_FUNC 110
#define PtAlert_FUNC 111
#define PtAppAddInput_FUNC 112
#define PtAppAddWorkProc_FUNC 113
#define PtAppCreatePulse_FUNC 114
#define PtAppDeletePulse_FUNC 115
#define PtAppProcessEvent_FUNC 116
#define PtAppPulseTrigger_FUNC 117
#define PtAppRemoveInput_FUNC 118
#define PtAppRemoveWorkProc_FUNC 119
#define PtBeep_FUNC 120
#define PtBlit_FUNC 121
#define PtBlockAllWindows_FUNC 122
#define PtBlockWindow_FUNC 123
#define PtButton_FUNC 124
#define PtCalcBorder_FUNC 125
#define PtCalcCanvas_FUNC 126
#define PtClippedBlit_FUNC 127
#define PtColorSelect_FUNC 128
#define PtComboBox_FUNC 129
#define PtContainer_FUNC 130
#define PtContainerFindFocus_FUNC 131
#define PtContainerFocusNext_FUNC 132
#define PtContainerFocusPrev_FUNC 133
#define PtContainerGiveFocus_FUNC 134
#define PtContainerHold_FUNC 135
#define PtContainerRelease_FUNC 136
#define PtCreateAppContext_FUNC 137
#define PtCreateWidget_FUNC 138
#define PtCreateWidgetClass_FUNC 139
#define PtDamageExtent_FUNC 140
#define PtDamageWidget_FUNC 141
#define PtDestroyWidget_FUNC 142
#define PtDisjoint_FUNC 143
#define PtEnter_FUNC 144
#define PtEventHandler_FUNC 145
#define PtExtentWidget_FUNC 146
#define PtExtentWidgetFamily_FUNC 147
#define PtFileSelection_FUNC 148
#define PtFindDisjoint_FUNC 149
#define PtFlush_FUNC 150
#define PtFontSelection_FUNC 151
#define PtForwardWindowEvent_FUNC 152
#define PtFrameSize_FUNC 153
#define PtGetAbsPosition_FUNC 154
#define PtGetResources_FUNC 155
#define PtGlobalFocusNext_FUNC 156
#define PtGlobalFocusNextContainer_FUNC 157
#define PtGlobalFocusPrev_FUNC 158
#define PtGlobalFocusPrevContainer_FUNC 159
#define PtGroup_FUNC 160
#define PtHit_FUNC 161
#define PtHold_FUNC 162
#define PtInflateBalloon_FUNC 163
#define PtInit_FUNC 164
#define PtIsFocused_FUNC 165
#define PtLabel_FUNC 166
#define PtLeave_FUNC 167
#define PtList_FUNC 168
#define PtListAddItems_FUNC 169
#define PtListDeleteAllItems_FUNC 170
#define PtListDeleteItemPos_FUNC 171
#define PtListGotoPos_FUNC 172
#define PtListItemPos_FUNC 173
#define PtListReplaceItemPos_FUNC 174
#define PtListSelectPos_FUNC 175
#define PtListUnselectPos_FUNC 176
#define PtMainLoop_FUNC 177
#define PtMenu_FUNC 178
#define PtMenuBar_FUNC 179
#define PtMenuButton_FUNC 180
#define PtMultiText_FUNC 181
#define PtNextTopLevelWidget_FUNC 182
#define PtPane_FUNC 183
#define PtPanelGroup_FUNC 184
#define PtPositionMenu_FUNC 185
#define PtProgress_FUNC 186
#define PtReParentWidget_FUNC 187
#define PtRealizeWidget_FUNC 188
#define PtRegion_FUNC 189
#define PtRelease_FUNC 190
#define PtRemoveCallback_FUNC 191
#define PtRemoveHotkeyHandler_FUNC 192
#define PtScrollArea_FUNC 193
#define PtScrollContainer_FUNC 194
#define PtScrollbar_FUNC 195
#define PtSendEventToWidget_FUNC 196
#define PtSeparator_FUNC 197
#define PtSetAreaFromWidgetCanvas_FUNC 198
#define PtSetParentWidget_FUNC 199
#define PtSetResource_FUNC 200
#define PtSetResources_FUNC 201
#define PtSlider_FUNC 202
#define PtSuperClassDraw_FUNC 203
#define PtSyncWidget_FUNC 204
#define PtText_FUNC 205
#define PtTextGetSelection_FUNC 206
#define PtTextModifyText__IIIIII_FUNC 207
#define PtTextModifyText__IIII_3BI_FUNC 208
#define PtTextSetSelection_FUNC 209
#define PtTimer_FUNC 210
#define PtToggleButton_FUNC 211
#define PtToolbar_FUNC 212
#define PtUnblockWindows_FUNC 213
#define PtUnrealizeWidget_FUNC 214
#define PtValidParent_FUNC 215
#define PtWebClient_FUNC 216
#define PtWidgetArea_FUNC 217
#define PtWidgetBrotherBehind_FUNC 218
#define PtWidgetBrotherInFront_FUNC 219
#define PtWidgetCanvas__II_FUNC 220
#define PtWidgetCanvas__ILorg_eclipse_swt_internal_photon_PhRect_1t_2_FUNC 221
#define PtWidgetChildBack_FUNC 222
#define PtWidgetChildFront_FUNC 223
#define PtWidgetClass_FUNC 224
#define PtWidgetExtent__II_FUNC 225
#define PtWidgetExtent__ILorg_eclipse_swt_internal_photon_PhRect_1t_2_FUNC 226
#define PtWidgetFlags_FUNC 227
#define PtWidgetInsert_FUNC 228
#define PtWidgetIsClassMember_FUNC 229
#define PtWidgetIsRealized_FUNC 230
#define PtWidgetOffset_FUNC 231
#define PtWidgetParent_FUNC 232
#define PtWidgetPreferredSize_FUNC 233
#define PtWidgetRid_FUNC 234
#define PtWidgetToBack_FUNC 235
#define PtWidgetToFront_FUNC 236
#define PtWindow_FUNC 237
#define PtWindowFocus_FUNC 238
#define PtWindowGetState_FUNC 239
#define PtWindowToBack_FUNC 240
#define PtWindowToFront_FUNC 241
#define free_FUNC 242
#define getenv_FUNC 243
#define malloc_FUNC 244
#define memmove__III_FUNC 245
#define memmove__ILorg_eclipse_swt_internal_photon_PgAlpha_1t_2I_FUNC 246
#define memmove__ILorg_eclipse_swt_internal_photon_PhArea_1t_2I_FUNC 247
#define memmove__ILorg_eclipse_swt_internal_photon_PhCursorDef_1t_2I_FUNC 248
#define memmove__ILorg_eclipse_swt_internal_photon_PhEvent_1t_2I_FUNC 249
#define memmove__ILorg_eclipse_swt_internal_photon_PhImage_1t_2I_FUNC 250
#define memmove__ILorg_eclipse_swt_internal_photon_PhPoint_1t_2I_FUNC 251
#define memmove__ILorg_eclipse_swt_internal_photon_PhPointerEvent_1t_2I_FUNC 252
#define memmove__ILorg_eclipse_swt_internal_photon_PhRect_1t_2I_FUNC 253
#define memmove__ILorg_eclipse_swt_internal_photon_PhTile_1t_2I_FUNC 254
#define memmove__ILorg_eclipse_swt_internal_photon_PtTextCallback_1t_2I_FUNC 255
#define memmove__ILorg_eclipse_swt_internal_photon_PtWebClientData_1t_2I_FUNC 256
#define memmove__I_3BI_FUNC 257
#define memmove__I_3II_FUNC 258
#define memmove__Lorg_eclipse_swt_internal_photon_FontDetails_2II_FUNC 259
#define memmove__Lorg_eclipse_swt_internal_photon_PgAlpha_1t_2II_FUNC 260
#define memmove__Lorg_eclipse_swt_internal_photon_PgMap_1t_2II_FUNC 261
#define memmove__Lorg_eclipse_swt_internal_photon_PhClipHeader_2II_FUNC 262
#define memmove__Lorg_eclipse_swt_internal_photon_PhEvent_1t_2II_FUNC 263
#define memmove__Lorg_eclipse_swt_internal_photon_PhImage_1t_2II_FUNC 264
#define memmove__Lorg_eclipse_swt_internal_photon_PhKeyEvent_1t_2II_FUNC 265
#define memmove__Lorg_eclipse_swt_internal_photon_PhPointerEvent_1t_2II_FUNC 266
#define memmove__Lorg_eclipse_swt_internal_photon_PhRect_1t_2II_FUNC 267
#define memmove__Lorg_eclipse_swt_internal_photon_PhTile_1t_2II_FUNC 268
#define memmove__Lorg_eclipse_swt_internal_photon_PhWindowEvent_1t_2II_FUNC 269
#define memmove__Lorg_eclipse_swt_internal_photon_PtCallbackInfo_1t_2II_FUNC 270
#define memmove__Lorg_eclipse_swt_internal_photon_PtScrollbarCallback_1t_2II_FUNC 271
#define memmove__Lorg_eclipse_swt_internal_photon_PtTextCallback_1t_2II_FUNC 272
#define memmove__Lorg_eclipse_swt_internal_photon_PtWebDataReqCallback_1t_2II_FUNC 273
#define memmove__Lorg_eclipse_swt_internal_photon_PtWebMetaDataCallback_1t_2II_FUNC 274
#define memmove__Lorg_eclipse_swt_internal_photon_PtWebStatusCallback_1t_2II_FUNC 275
#define memmove__Lorg_eclipse_swt_internal_photon_PtWebWindowCallback_1t_2II_FUNC 276
#define memmove___3BII_FUNC 277
#define memmove___3BLorg_eclipse_swt_internal_photon_PhClipHeader_2I_FUNC 278
#define memmove___3III_FUNC 279
#define memmove___3SII_FUNC 280
#define memset_FUNC 281
#define strdup_FUNC 282
#define strlen_FUNC 283
#define uname_FUNC 284
