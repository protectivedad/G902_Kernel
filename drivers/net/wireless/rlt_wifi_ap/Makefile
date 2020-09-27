EXTRA_CFLAGS = -Idrivers/net/wireless/linux-2.6.36.x/drivers/net/wireless/rlt_wifi/include \
		-Idrivers/net/wireless/linux-2.6.36.x/drivers/net/wireless/rlt_wifi/ate/include

WIFI_HEAD_GEN  = $(shell make -C drivers/net/wireless/rlt_wifi RT28xx_MODE=AP CHIPSET=mt7603e EE_TYPE=$(CONFIG_MT_PA_LNA) sdk_build_tools >/dev/null)

DRV_NAME = rlt_wifi
MT_WIFI_DIR = ../rlt_wifi
obj-$(CONFIG_RLT_AP_SUPPORT) += rlt_wifi.o
rlt_wifi-y := rlt_wifi.bk

###################
#  CFLAGS
##################
EXTRA_CFLAGS += -DAGGREGATION_SUPPORT -DPIGGYBACK_SUPPORT -DWMM_SUPPORT  -DLINUX \
               -Wall -Wstrict-prototypes -Wno-trigraphs
#-DDBG_DIAGNOSE -DDBG_RX_MCS -DDBG_TX_MCS

EXTRA_CFLAGS += -DCONFIG_AP_SUPPORT -DSCAN_SUPPORT -DAP_SCAN_SUPPORT
EXTRA_CFLAGS += -DDOT11_N_SUPPORT -DSTATS_COUNT_SUPPORT -DIAPP_SUPPORT -DDOT1X_SUPPORT
#EXTRA_CFLAGS += -DRALINK_ATE -DRALINK_QA -DCONFIG_RT2880_ATE_CMD_NEW
EXTRA_CFLAGS += -DCONFIG_RA_NAT_NONE

#provide busy time statistics for every TBTT */
#EXTRA_CFLAGS += -DQLOAD_FUNC_BUSY_TIME_STATS 

# provide busy time alarm mechanism 
# use the function to avoid to locate in some noise environments 
#EXTRA_CFLAGS += -DQLOAD_FUNC_BUSY_TIME_ALARM

ifeq ($(CONFIG_RT2860V2_AUTO_CH_SELECT_ENCANCE),y)
EXTRA_CFLAGS += -DAUTO_CH_SELECT_ENHANCE
endif

ifeq ($(CONFIG_RT2860V2_SNMP),y)
EXTRA_CFLAGS += -DSNMP_SUPPORT
endif

ifeq ($(CONFIG_RT2860V2_AP_32B_DESC),y)
EXTRA_CFLAGS += -DDESC_32B_SUPPORT
endif

ifeq ($(CONFIG_RT2860V2_HW_ANTENNA_DIVERSITY),y)
EXTRA_CFLAGS += -DHW_ANTENNA_DIVERSITY_SUPPORT
endif

ifeq ($(CONFIG_RT2860V2_EXT_CHANNEL_LIST),y)
EXTRA_CFLAGS += -DEXT_BUILD_CHANNEL_LIST
endif

ifeq ($(CONFIG_MT_MEMORY_OPTIMIZATION),y)
EXTRA_CFLAGS += -DMEMORY_OPTIMIZATION
else
EXTRA_CFLAGS += -DDBG
endif

ifeq ($(CONFIG_MT_RTMP_INTERNAL_TX_ALC),y)
EXTRA_CFLAGS += -DRTMP_INTERNAL_TX_ALC
endif

EXTRA_CFLAGS += -DIP_ASSEMBLY
#ifeq ($(CONFIG_RT2860V2_AP_RTMP_TEMPERATURE_CALIBRATION),y)
#ifeq ($(CONFIG_RALINK_MT7620),y)
#EXTRA_CFLAGS   += -DRTMP_TEMPERATURE_CALIBRATION
#endif
#endif

MODULE_FLAGS=$(EXTRA_CFLAGS)
export MODULE_FLAGS
obj-m+=$(MT_WIFI_DIR)/tools/plug_in/
