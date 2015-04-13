#ifndef __JZ_LCD_OPS5_H__
#define __JZ_LCD_OPS5_H__
/***************************************************************************
 * LCD
 ***************************************************************************/
#define __lcd_enable_tvepeh() 		( REG_LCD_CFG |= LCD_CFG_TVEPEH )
#define __lcd_disable_tvepeh() 		( REG_LCD_CFG &= ~LCD_CFG_TVEPEH )

#define __lcd_enable_fuhold() 		( REG_LCD_CFG |= LCD_CFG_FUHOLD )
#define __lcd_disable_fuhold() 		( REG_LCD_CFG &= ~LCD_CFG_FUHOLD )

#define __lcd_des_8word() 		( REG_LCD_CFG |= LCD_CFG_NEWDES )
#define __lcd_des_4word() 		( REG_LCD_CFG &= ~LCD_CFG_NEWDES )

#define __lcd_enable_bypass_pal() 	( REG_LCD_CFG |= LCD_CFG_PALBP )
#define __lcd_disable_bypass_pal() 	( REG_LCD_CFG &= ~LCD_CFG_PALBP )

#define __lcd_set_lcdpnl_term()		( REG_LCD_CTRL |= LCD_CFG_TVEN )
#define __lcd_set_tv_term()		( REG_LCD_CTRL &= ~LCD_CFG_TVEN )

#define __lcd_enable_auto_recover() 	( REG_LCD_CFG |= LCD_CFG_RECOVER )
#define __lcd_disable_auto_recover() 	( REG_LCD_CFG &= ~LCD_CFG_RECOVER )

#define __lcd_enable_dither() 	        ( REG_LCD_CFG |= LCD_CFG_DITHER )
#define __lcd_disable_dither() 	        ( REG_LCD_CFG &= ~LCD_CFG_DITHER )

#define __lcd_disable_ps_mode()	        ( REG_LCD_CFG |= LCD_CFG_PSM )
#define __lcd_enable_ps_mode()	        ( REG_LCD_CFG &= ~LCD_CFG_PSM )

#define __lcd_disable_cls_mode() 	( REG_LCD_CFG |= LCD_CFG_CLSM )
#define __lcd_enable_cls_mode()	        ( REG_LCD_CFG &= ~LCD_CFG_CLSM )

#define __lcd_disable_spl_mode() 	( REG_LCD_CFG |= LCD_CFG_SPLM )
#define __lcd_enable_spl_mode()	        ( REG_LCD_CFG &= ~LCD_CFG_SPLM )

#define __lcd_disable_rev_mode() 	( REG_LCD_CFG |= LCD_CFG_REVM )
#define __lcd_enable_rev_mode()	        ( REG_LCD_CFG &= ~LCD_CFG_REVM )

#define __lcd_disable_hsync_mode() 	( REG_LCD_CFG |= LCD_CFG_HSYNM )
#define __lcd_enable_hsync_mode()	( REG_LCD_CFG &= ~LCD_CFG_HSYNM )

#define __lcd_disable_pclk_mode() 	( REG_LCD_CFG |= LCD_CFG_PCLKM )
#define __lcd_enable_pclk_mode()	( REG_LCD_CFG &= ~LCD_CFG_PCLKM )

#define __lcd_normal_outdata()          ( REG_LCD_CFG &= ~LCD_CFG_INVDAT )
#define __lcd_inverse_outdata()         ( REG_LCD_CFG |= LCD_CFG_INVDAT )

#define __lcd_sync_input()              ( REG_LCD_CFG |= LCD_CFG_SYNDIR_IN )
#define __lcd_sync_output()             ( REG_LCD_CFG &= ~LCD_CFG_SYNDIR_IN )

#define __lcd_hsync_active_high()       ( REG_LCD_CFG &= ~LCD_CFG_HSP )
#define __lcd_hsync_active_low()        ( REG_LCD_CFG |= LCD_CFG_HSP )

#define __lcd_pclk_rising()             ( REG_LCD_CFG &= ~LCD_CFG_PCP )
#define __lcd_pclk_falling()            ( REG_LCD_CFG |= LCD_CFG_PCP )

#define __lcd_de_active_high()          ( REG_LCD_CFG &= ~LCD_CFG_DEP )
#define __lcd_de_active_low()           ( REG_LCD_CFG |= LCD_CFG_DEP )

#define __lcd_vsync_rising()            ( REG_LCD_CFG &= ~LCD_CFG_VSP )
#define __lcd_vsync_falling()           ( REG_LCD_CFG |= LCD_CFG_VSP )

#define __lcd_set_16_tftpnl() \
  ( REG_LCD_CFG = (REG_LCD_CFG & ~LCD_CFG_MODE_TFT_MASK) | LCD_CFG_MODE_TFT_16BIT )

#define __lcd_set_18_tftpnl() \
  ( REG_LCD_CFG = (REG_LCD_CFG & ~LCD_CFG_MODE_TFT_MASK) | LCD_CFG_MODE_TFT_18BIT )

#define __lcd_set_24_tftpnl()		( REG_LCD_CFG |= LCD_CFG_MODE_TFT_24BIT )

/*
 * n=1,2,4,8 for single mono-STN
 * n=4,8 for dual mono-STN
 */
#define __lcd_set_panel_datawidth(n) 		\
do { 						\
	REG_LCD_CFG &= ~LCD_CFG_PDW_MASK; 	\
	REG_LCD_CFG |= LCD_CFG_PDW_n##;		\
} while (0)

/* m = LCD_CFG_MODE_GENERUIC_TFT_xxx */
#define __lcd_set_panel_mode(m) 		\
do {						\
	REG_LCD_CFG &= ~LCD_CFG_MODE_MASK;	\
	REG_LCD_CFG |= (m);			\
} while(0)

/* n=4,8,16 */
#define __lcd_set_burst_length(n) 		\
do {						\
	REG_LCD_CTRL &= ~LCD_CTRL_BST_MASK;	\
	REG_LCD_CTRL |= LCD_CTRL_BST_n##;	\
} while (0)

#define __lcd_select_rgb565()		( REG_LCD_CTRL &= ~LCD_CTRL_RGB555 )
#define __lcd_select_rgb555()		( REG_LCD_CTRL |= LCD_CTRL_RGB555 )

#define __lcd_set_ofup()		( REG_LCD_CTRL |= LCD_CTRL_OFUP )
#define __lcd_clr_ofup()		( REG_LCD_CTRL &= ~LCD_CTRL_OFUP )

/* n=2,4,16 */
#define __lcd_set_stn_frc(n) 			\
do {						\
	REG_LCD_CTRL &= ~LCD_CTRL_FRC_MASK;	\
	REG_LCD_CTRL |= LCD_CTRL_FRC_n##;	\
} while (0)

#define __lcd_enable_eof_intr()		( REG_LCD_CTRL |= LCD_CTRL_EOFM )
#define __lcd_disable_eof_intr()	( REG_LCD_CTRL &= ~LCD_CTRL_EOFM )

#define __lcd_enable_sof_intr()		( REG_LCD_CTRL |= LCD_CTRL_SOFM )
#define __lcd_disable_sof_intr()	( REG_LCD_CTRL &= ~LCD_CTRL_SOFM )

#define __lcd_enable_ofu_intr()		( REG_LCD_CTRL |= LCD_CTRL_OFUM )
#define __lcd_disable_ofu_intr()	( REG_LCD_CTRL &= ~LCD_CTRL_OFUM )

#define __lcd_enable_ifu0_intr()	( REG_LCD_CTRL |= LCD_CTRL_IFUM0 )
#define __lcd_disable_ifu0_intr()	( REG_LCD_CTRL &= ~LCD_CTRL_IFUM0 )

#define __lcd_enable_ifu1_intr()	( REG_LCD_CTRL |= LCD_CTRL_IFUM1 )
#define __lcd_disable_ifu1_intr()	( REG_LCD_CTRL &= ~LCD_CTRL_IFUM1 )

#define __lcd_enable_ldd_intr()		( REG_LCD_CTRL |= LCD_CTRL_LDDM )
#define __lcd_disable_ldd_intr()	( REG_LCD_CTRL &= ~LCD_CTRL_LDDM )

#define __lcd_enable_qd_intr()		( REG_LCD_CTRL |= LCD_CTRL_QDM )
#define __lcd_disable_qd_intr()		( REG_LCD_CTRL &= ~LCD_CTRL_QDM )

#define __lcd_reverse_byte_endian()	( REG_LCD_CTRL |= LCD_CTRL_BEDN )
#define __lcd_normal_byte_endian()	( REG_LCD_CTRL &= ~LCD_CTRL_BEDN )

#define __lcd_pixel_endian_little()	( REG_LCD_CTRL |= LCD_CTRL_PEDN )
#define __lcd_pixel_endian_big()	( REG_LCD_CTRL &= ~LCD_CTRL_PEDN )

#define __lcd_set_dis()			( REG_LCD_CTRL |= LCD_CTRL_DIS )
#define __lcd_clr_dis()			( REG_LCD_CTRL &= ~LCD_CTRL_DIS )

#define __lcd_set_ena()			( REG_LCD_CTRL |= LCD_CTRL_ENA )
#define __lcd_clr_ena()			( REG_LCD_CTRL &= ~LCD_CTRL_ENA )

/* n=1,2,4,8,16 */
#define __lcd_set_bpp(n) \
  ( REG_LCD_CTRL = (REG_LCD_CTRL & ~LCD_CTRL_BPP_MASK) | LCD_CTRL_BPP_##n )

/* LCD status register indication */

#define __lcd_quick_disable_done()	( REG_LCD_STATE & LCD_STATE_QD )
#define __lcd_disable_done()		( REG_LCD_STATE & LCD_STATE_LDD )
#define __lcd_infifo0_underrun()	( REG_LCD_STATE & LCD_STATE_IFU0 )
#define __lcd_infifo1_underrun()	( REG_LCD_STATE & LCD_STATE_IFU1 )
#define __lcd_outfifo_underrun()	( REG_LCD_STATE & LCD_STATE_OFU )
#define __lcd_start_of_frame()		( REG_LCD_STATE & LCD_STATE_SOF )
#define __lcd_end_of_frame()		( REG_LCD_STATE & LCD_STATE_EOF )

#define __lcd_clr_outfifounderrun()	( REG_LCD_STATE &= ~LCD_STATE_OFU )
#define __lcd_clr_sof()			( REG_LCD_STATE &= ~LCD_STATE_SOF )
#define __lcd_clr_eof()			( REG_LCD_STATE &= ~LCD_STATE_EOF )

/* OSD functions */
#define __lcd_enable_osd() 	(REG_LCD_OSDC |= LCD_OSDC_OSDEN)
#define __lcd_enable_f0() 	(REG_LCD_OSDC |= LCD_OSDC_F0EN)
#define __lcd_enable_f1()	(REG_LCD_OSDC |= LCD_OSDC_F1EN)
#define __lcd_enable_alpha() 	(REG_LCD_OSDC |= LCD_OSDC_ALPHAEN)
#define __lcd_enable_alphamd()	(REG_LCD_OSDC |= LCD_OSDC_ALPHAMD)

#define __lcd_disable_osd()	(REG_LCD_OSDC &= ~LCD_OSDC_OSDEN)
#define __lcd_disable_f0() 	(REG_LCD_OSDC &= ~LCD_OSDC_F0EN)
#define __lcd_disable_f1() 	(REG_LCD_OSDC &= ~LCD_OSDC_F1EN)
#define __lcd_disable_alpha()	(REG_LCD_OSDC &= ~LCD_OSDC_ALPHAEN)
#define __lcd_disable_alphamd()	(REG_LCD_OSDC &= ~LCD_OSDC_ALPHAMD)

/* OSD Controll Register */
#define __lcd_fg1_use_ipu() 		(REG_LCD_OSDCTRL |= LCD_OSDCTRL_IPU)
#define __lcd_fg1_use_dma_chan1() 	(REG_LCD_OSDCTRL &= ~LCD_OSDCTRL_IPU)
#define __lcd_fg1_unuse_ipu() 		__lcd_fg1_use_dma_chan1()
#define __lcd_osd_rgb555_mode()         ( REG_LCD_OSDCTRL |= LCD_OSDCTRL_RGB555 )
#define __lcd_osd_rgb565_mode()         ( REG_LCD_OSDCTRL &= ~LCD_OSDCTRL_RGB555 )
#define __lcd_osd_change_size()         ( REG_LCD_OSDCTRL |= LCD_OSDCTRL_CHANGES )
#define __lcd_osd_bpp_15_16() \
  ( REG_LCD_OSDCTRL = (REG_LCD_OSDCTRL & ~LCD_OSDCTRL_OSDBPP_MASK) | LCD_OSDCTRL_OSDBPP_15_16 )
#define __lcd_osd_bpp_18_24() \
  ( REG_LCD_OSDCTRL = (REG_LCD_OSDCTRL & ~LCD_OSDCTRL_OSDBPP_MASK) | LCD_OSDCTRL_OSDBPP_18_24 )

/* OSD State Register */
#define __lcd_start_of_fg1()		( REG_LCD_STATE & LCD_OSDS_SOF1 )
#define __lcd_end_of_fg1()		( REG_LCD_STATE & LCD_OSDS_EOF1 )
#define __lcd_start_of_fg0()		( REG_LCD_STATE & LCD_OSDS_SOF0 )
#define __lcd_end_of_fg0()		( REG_LCD_STATE & LCD_OSDS_EOF0 )
#define __lcd_change_is_rdy()		( REG_LCD_STATE & LCD_OSDS_READY )

/* Foreground Color Key Register 0,1(foreground 0, foreground 1) */
#define __lcd_enable_colorkey0()	(REG_LCD_KEY0 |= LCD_KEY_KEYEN)
#define __lcd_enable_colorkey1()	(REG_LCD_KEY1 |= LCD_KEY_KEYEN)
#define __lcd_enable_colorkey0_md() 	(REG_LCD_KEY0 |= LCD_KEY_KEYMD)
#define __lcd_enable_colorkey1_md() 	(REG_LCD_KEY1 |= LCD_KEY_KEYMD)
#define __lcd_set_colorkey0(key) 	(REG_LCD_KEY0 = (REG_LCD_KEY0&~0xFFFFFF)|(key))
#define __lcd_set_colorkey1(key) 	(REG_LCD_KEY1 = (REG_LCD_KEY1&~0xFFFFFF)|(key))

#define __lcd_disable_colorkey0() 	(REG_LCD_KEY0 &= ~LCD_KEY_KEYEN)
#define __lcd_disable_colorkey1() 	(REG_LCD_KEY1 &= ~LCD_KEY_KEYEN)
#define __lcd_disable_colorkey0_md() 	(REG_LCD_KEY0 &= ~LCD_KEY_KEYMD)
#define __lcd_disable_colorkey1_md() 	(REG_LCD_KEY1 &= ~LCD_KEY_KEYMD)

/* IPU Restart Register */
#define __lcd_enable_ipu_restart() 	(REG_LCD_IPUR |= LCD_IPUR_IPUREN)
#define __lcd_disable_ipu_restart() 	(REG_LCD_IPUR &= ~LCD_IPUR_IPUREN)
#define __lcd_set_ipu_restart_triger(n)	(REG_LCD_IPUR = (REG_LCD_IPUR&(~0xFFFFFF))|(n))

/* RGB Control Register */
#define __lcd_enable_rgb_dummy() 	(REG_LCD_RGBC |= LCD_RGBC_RGBDM)
#define __lcd_disable_rgb_dummy() 	(REG_LCD_RGBC &= ~LCD_RGBC_RGBDM)

#define __lcd_dummy_rgb() 	(REG_LCD_RGBC |= LCD_RGBC_DMM)
#define __lcd_rgb_dummy() 	(REG_LCD_RGBC &= ~LCD_RGBC_DMM)

#define __lcd_rgb2ycc() 	(REG_LCD_RGBC |= LCD_RGBC_YCC)
#define __lcd_notrgb2ycc() 	(REG_LCD_RGBC &= ~LCD_RGBC_YCC)

#define __lcd_odd_mode_rgb() \
  ( REG_LCD_RGBC = (REG_LCD_RGBC & ~LCD_RGBC_ODDRGB_MASK) | LCD_RGBC_ODD_RGB )
#define __lcd_odd_mode_rbg() \
  ( REG_LCD_RGBC = (REG_LCD_RGBC & ~LCD_RGBC_ODDRGB_MASK) | LCD_RGBC_ODD_RBG )
#define __lcd_odd_mode_grb() \
  ( REG_LCD_RGBC = (REG_LCD_RGBC & ~LCD_RGBC_ODDRGB_MASK) | LCD_RGBC_ODD_GRB)

#define __lcd_odd_mode_gbr() \
  ( REG_LCD_RGBC = (REG_LCD_RGBC & ~LCD_RGBC_ODDRGB_MASK) | LCD_RGBC_ODD_GBR)
#define __lcd_odd_mode_brg() \
  ( REG_LCD_RGBC = (REG_LCD_RGBC & ~LCD_RGBC_ODDRGB_MASK) | LCD_RGBC_ODD_BRG)
#define __lcd_odd_mode_bgr() \
  ( REG_LCD_RGBC = (REG_LCD_RGBC & ~LCD_RGBC_ODDRGB_MASK) | LCD_RGBC_ODD_BGR)

#define __lcd_even_mode_rgb() \
  ( REG_LCD_RGBC = (REG_LCD_RGBC & ~LCD_RGBC_EVENRGB_MASK) | LCD_RGBC_EVEN_RGB )
#define __lcd_even_mode_rbg() \
  ( REG_LCD_RGBC = (REG_LCD_RGBC & ~LCD_RGBC_EVENRGB_MASK) | LCD_RGBC_EVEN_RBG )
#define __lcd_even_mode_grb() \
  ( REG_LCD_RGBC = (REG_LCD_RGBC & ~LCD_RGBC_EVENRGB_MASK) | LCD_RGBC_EVEN_GRB)

#define __lcd_even_mode_gbr() \
  ( REG_LCD_RGBC = (REG_LCD_RGBC & ~LCD_RGBC_EVENRGB_MASK) | LCD_RGBC_EVEN_GBR)
#define __lcd_even_mode_brg() \
  ( REG_LCD_RGBC = (REG_LCD_RGBC & ~LCD_RGBC_EVENRGB_MASK) | LCD_RGBC_EVEN_BRG)
#define __lcd_even_mode_bgr() \
  ( REG_LCD_RGBC = (REG_LCD_RGBC & ~LCD_RGBC_EVENRGB_MASK) | LCD_RGBC_EVEN_BGR)

/* Vertical Synchronize Register */
#define __lcd_vsync_get_vps() \
  ( (REG_LCD_VSYNC & LCD_VSYNC_VPS_MASK) >> LCD_VSYNC_VPS_BIT )

#define __lcd_vsync_get_vpe() \
  ( (REG_LCD_VSYNC & LCD_VSYNC_VPE_MASK) >> LCD_VSYNC_VPE_BIT )
#define __lcd_vsync_set_vpe(n) 				\
do {							\
	REG_LCD_VSYNC &= ~LCD_VSYNC_VPE_MASK;		\
	REG_LCD_VSYNC |= (n) << LCD_VSYNC_VPE_BIT;	\
} while (0)

#define __lcd_hsync_get_hps() \
  ( (REG_LCD_HSYNC & LCD_HSYNC_HPS_MASK) >> LCD_HSYNC_HPS_BIT )
#define __lcd_hsync_set_hps(n) 				\
do {							\
	REG_LCD_HSYNC &= ~LCD_HSYNC_HPS_MASK;		\
	REG_LCD_HSYNC |= (n) << LCD_HSYNC_HPS_BIT;	\
} while (0)

#define __lcd_hsync_get_hpe() \
  ( (REG_LCD_HSYNC & LCD_HSYNC_HPE_MASK) >> LCD_VSYNC_HPE_BIT )
#define __lcd_hsync_set_hpe(n) 				\
do {							\
	REG_LCD_HSYNC &= ~LCD_HSYNC_HPE_MASK;		\
	REG_LCD_HSYNC |= (n) << LCD_HSYNC_HPE_BIT;	\
} while (0)

#define __lcd_vat_get_ht() \
  ( (REG_LCD_VAT & LCD_VAT_HT_MASK) >> LCD_VAT_HT_BIT )
#define __lcd_vat_set_ht(n) 				\
do {							\
	REG_LCD_VAT &= ~LCD_VAT_HT_MASK;		\
	REG_LCD_VAT |= (n) << LCD_VAT_HT_BIT;		\
} while (0)

#define __lcd_vat_get_vt() \
  ( (REG_LCD_VAT & LCD_VAT_VT_MASK) >> LCD_VAT_VT_BIT )
#define __lcd_vat_set_vt(n) 				\
do {							\
	REG_LCD_VAT &= ~LCD_VAT_VT_MASK;		\
	REG_LCD_VAT |= (n) << LCD_VAT_VT_BIT;		\
} while (0)

#define __lcd_dah_get_hds() \
  ( (REG_LCD_DAH & LCD_DAH_HDS_MASK) >> LCD_DAH_HDS_BIT )
#define __lcd_dah_set_hds(n) 				\
do {							\
	REG_LCD_DAH &= ~LCD_DAH_HDS_MASK;		\
	REG_LCD_DAH |= (n) << LCD_DAH_HDS_BIT;		\
} while (0)

#define __lcd_dah_get_hde() \
  ( (REG_LCD_DAH & LCD_DAH_HDE_MASK) >> LCD_DAH_HDE_BIT )
#define __lcd_dah_set_hde(n) 				\
do {							\
	REG_LCD_DAH &= ~LCD_DAH_HDE_MASK;		\
	REG_LCD_DAH |= (n) << LCD_DAH_HDE_BIT;		\
} while (0)

#define __lcd_dav_get_vds() \
  ( (REG_LCD_DAV & LCD_DAV_VDS_MASK) >> LCD_DAV_VDS_BIT )
#define __lcd_dav_set_vds(n) 				\
do {							\
	REG_LCD_DAV &= ~LCD_DAV_VDS_MASK;		\
	REG_LCD_DAV |= (n) << LCD_DAV_VDS_BIT;		\
} while (0)

#define __lcd_dav_get_vde() \
  ( (REG_LCD_DAV & LCD_DAV_VDE_MASK) >> LCD_DAV_VDE_BIT )
#define __lcd_dav_set_vde(n) 				\
do {							\
	REG_LCD_DAV &= ~LCD_DAV_VDE_MASK;		\
	REG_LCD_DAV |= (n) << LCD_DAV_VDE_BIT;		\
} while (0)

/* DMA Command Register */
#define __lcd_cmd0_set_sofint()		( REG_LCD_CMD0 |= LCD_CMD_SOFINT )
#define __lcd_cmd0_clr_sofint()		( REG_LCD_CMD0 &= ~LCD_CMD_SOFINT )
#define __lcd_cmd1_set_sofint()		( REG_LCD_CMD1 |= LCD_CMD_SOFINT )
#define __lcd_cmd1_clr_sofint()		( REG_LCD_CMD1 &= ~LCD_CMD_SOFINT )

#define __lcd_cmd0_set_eofint()		( REG_LCD_CMD0 |= LCD_CMD_EOFINT )
#define __lcd_cmd0_clr_eofint()		( REG_LCD_CMD0 &= ~LCD_CMD_EOFINT )
#define __lcd_cmd1_set_eofint()		( REG_LCD_CMD1 |= LCD_CMD_EOFINT )
#define __lcd_cmd1_clr_eofint()		( REG_LCD_CMD1 &= ~LCD_CMD_EOFINT )

#define __lcd_cmd0_set_pal()		( REG_LCD_CMD0 |= LCD_CMD_PAL )
#define __lcd_cmd0_clr_pal()		( REG_LCD_CMD0 &= ~LCD_CMD_PAL )

#define __lcd_cmd0_get_len() \
  ( (REG_LCD_CMD0 & LCD_CMD_LEN_MASK) >> LCD_CMD_LEN_BIT )
#define __lcd_cmd1_get_len() \
  ( (REG_LCD_CMD1 & LCD_CMD_LEN_MASK) >> LCD_CMD_LEN_BIT )

#endif /* __JZ_LCD_OPS5_H__ */
