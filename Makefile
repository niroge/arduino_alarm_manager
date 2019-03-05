#############################################################################
# Makefile for building: arduino_alarm_manager
# Generated by qmake (3.1) (Qt 5.12.1)
# Project:  arduino_alarm_manager.pro
# Template: app
# Command: /usr/lib64/qt5/bin/qmake -o Makefile arduino_alarm_manager.pro
#############################################################################

MAKEFILE      = Makefile

EQ            = =

####### Compiler, tools and options

CC            = gcc
CXX           = g++
DEFINES       = -DQT_DEPRECATED_WARNINGS -DQT_NO_DEBUG -DQT_WIDGETS_LIB -DQT_GUI_LIB -DQT_CORE_LIB
CFLAGS        = -pipe -O2 -Wall -W -D_REENTRANT -fPIC $(DEFINES)
CXXFLAGS      = -pipe -O2 -Wall -W -D_REENTRANT -fPIC $(DEFINES)
INCPATH       = -I. -I. -isystem /usr/include/qt5 -isystem /usr/include/qt5/QtWidgets -isystem /usr/include/qt5/QtGui -isystem /usr/include/qt5/QtCore -I. -isystem /usr/include/libdrm -I/usr/lib64/qt5/mkspecs/linux-g++
QMAKE         = /usr/lib64/qt5/bin/qmake
DEL_FILE      = rm -f
CHK_DIR_EXISTS= test -d
MKDIR         = mkdir -p
COPY          = cp -f
COPY_FILE     = cp -f
COPY_DIR      = cp -f -R
INSTALL_FILE  = install -m 644 -p
INSTALL_PROGRAM = install -m 755 -p
INSTALL_DIR   = cp -f -R
QINSTALL      = /usr/lib64/qt5/bin/qmake -install qinstall
QINSTALL_PROGRAM = /usr/lib64/qt5/bin/qmake -install qinstall -exe
DEL_FILE      = rm -f
SYMLINK       = ln -f -s
DEL_DIR       = rmdir
MOVE          = mv -f
TAR           = tar -cf
COMPRESS      = gzip -9f
DISTNAME      = arduino_alarm_manager1.0.0
DISTDIR = /home/conway/Code/arduino_alarm_manager/.tmp/arduino_alarm_manager1.0.0
LINK          = g++
LFLAGS        = -Wl,-O1
LIBS          = $(SUBLIBS) -lQt5Widgets -lQt5Gui -lQt5Core /usr/lib64/libGL.so -lpthread -lbluetooth
AR            = ar cqs
RANLIB        = 
SED           = sed
STRIP         = strip

####### Output directory

OBJECTS_DIR   = ./

####### Files

SOURCES       = arduino_alarm_manager.cc 
OBJECTS       = arduino_alarm_manager.o
DIST          = /usr/lib64/qt5/mkspecs/features/spec_pre.prf \
		/usr/lib64/qt5/mkspecs/common/unix.conf \
		/usr/lib64/qt5/mkspecs/common/linux.conf \
		/usr/lib64/qt5/mkspecs/common/sanitize.conf \
		/usr/lib64/qt5/mkspecs/common/gcc-base.conf \
		/usr/lib64/qt5/mkspecs/common/gcc-base-unix.conf \
		/usr/lib64/qt5/mkspecs/common/g++-base.conf \
		/usr/lib64/qt5/mkspecs/common/g++-unix.conf \
		/usr/lib64/qt5/mkspecs/qconfig.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_Attica.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_Baloo.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_BluezQt.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_KActivities.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_KActivitiesStats.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_KArchive.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_KAuth.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_KBookmarks.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_KCMUtils.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_KCodecs.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_KCompletion.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_KConfigCore.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_KConfigGui.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_KConfigWidgets.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_KCoreAddons.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_KCrash.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_KDBusAddons.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_KDeclarative.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_KDESu.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_KDNSSD.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_KEmoticons.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_KFileMetaData.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_KGlobalAccel.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_KGuiAddons.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_KHolidays.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_KHtml.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_KI18n.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_KIconThemes.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_KIdleTime.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_KIOCore.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_KIOFileWidgets.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_KIOGui.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_KIOWidgets.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_Kirigami2.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_KItemModels.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_KItemViews.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_KJobWidgets.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_KJS.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_KJSApi.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_KJsEmbed.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_KNewStuff.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_KNewStuffCore.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_KNotifications.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_KNotifyConfig.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_KNTLM.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_KParts.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_KPeople.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_KPeopleWidgets.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_KPty.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_KrossCore.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_KrossUi.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_KRunner.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_KScreen.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_KService.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_KSyntaxHighlighting.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_KTextEditor.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_KTextWidgets.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_KUnitConversion.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_KWallet.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_KWaylandClient.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_KWaylandServer.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_KWidgetsAddons.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_KWindowSystem.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_KXmlGui.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_KXmlRpcClient.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_accessibility_support_private.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_bootstrap_private.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_concurrent.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_concurrent_private.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_core.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_core_private.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_dbus.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_dbus_private.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_designer.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_designer_private.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_designercomponents_private.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_devicediscovery_support_private.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_edid_support_private.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_egl_support_private.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_eventdispatcher_support_private.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_fb_support_private.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_fontdatabase_support_private.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_glx_support_private.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_gui.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_gui_private.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_hunspellinputmethod_private.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_linuxaccessibility_support_private.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_network.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_network_private.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_openglextensions.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_openglextensions_private.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_packetprotocol_private.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_platformcompositor_support_private.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_printsupport.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_printsupport_private.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_qml.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_qml_private.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_qmldebug_private.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_qmldevtools_private.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_qmltest.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_qmltest_private.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_quick.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_quick_private.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_quickcontrols2.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_quickcontrols2_private.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_quickparticles_private.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_quickshapes_private.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_quicktemplates2_private.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_quickwidgets.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_quickwidgets_private.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_script.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_script_private.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_scripttools.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_scripttools_private.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_sensors.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_sensors_private.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_service_support_private.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_sql.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_sql_private.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_svg.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_svg_private.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_testlib.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_testlib_private.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_theme_support_private.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_uiplugin.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_uitools.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_uitools_private.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_virtualkeyboard.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_virtualkeyboard_private.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_waylandclient.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_waylandclient_private.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_waylandcompositor.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_waylandcompositor_private.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_widgets.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_widgets_private.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_x11extras.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_x11extras_private.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_xcb_qpa_lib_private.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_xml.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_xml_private.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_xmlpatterns.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_xmlpatterns_private.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_NetworkManagerQt.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_phonon4qt5.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_QuickAddons.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_Solid.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_SonnetCore.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_SonnetUi.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_ThreadWeaver.pri \
		/usr/lib64/qt5/mkspecs/features/qt_functions.prf \
		/usr/lib64/qt5/mkspecs/features/qt_config.prf \
		/usr/lib64/qt5/mkspecs/linux-g++/qmake.conf \
		/usr/lib64/qt5/mkspecs/features/spec_post.prf \
		/usr/lib64/qt5/mkspecs/features/exclusive_builds.prf \
		/usr/lib64/qt5/mkspecs/features/toolchain.prf \
		/usr/lib64/qt5/mkspecs/features/default_pre.prf \
		/usr/lib64/qt5/mkspecs/features/resolve_config.prf \
		/usr/lib64/qt5/mkspecs/features/default_post.prf \
		/usr/lib64/qt5/mkspecs/features/warn_on.prf \
		/usr/lib64/qt5/mkspecs/features/qt.prf \
		/usr/lib64/qt5/mkspecs/features/resources.prf \
		/usr/lib64/qt5/mkspecs/features/moc.prf \
		/usr/lib64/qt5/mkspecs/features/unix/opengl.prf \
		/usr/lib64/qt5/mkspecs/features/uic.prf \
		/usr/lib64/qt5/mkspecs/features/unix/thread.prf \
		/usr/lib64/qt5/mkspecs/features/qmake_use.prf \
		/usr/lib64/qt5/mkspecs/features/file_copies.prf \
		/usr/lib64/qt5/mkspecs/features/testcase_targets.prf \
		/usr/lib64/qt5/mkspecs/features/exceptions.prf \
		/usr/lib64/qt5/mkspecs/features/yacc.prf \
		/usr/lib64/qt5/mkspecs/features/lex.prf \
		arduino_alarm_manager.pro  arduino_alarm_manager.cc
QMAKE_TARGET  = arduino_alarm_manager
DESTDIR       = 
TARGET        = arduino_alarm_manager


first: all
####### Build rules

arduino_alarm_manager:  $(OBJECTS)  
	$(LINK) $(LFLAGS) -o $(TARGET) $(OBJECTS) $(OBJCOMP) $(LIBS)

Makefile: arduino_alarm_manager.pro /usr/lib64/qt5/mkspecs/linux-g++/qmake.conf /usr/lib64/qt5/mkspecs/features/spec_pre.prf \
		/usr/lib64/qt5/mkspecs/common/unix.conf \
		/usr/lib64/qt5/mkspecs/common/linux.conf \
		/usr/lib64/qt5/mkspecs/common/sanitize.conf \
		/usr/lib64/qt5/mkspecs/common/gcc-base.conf \
		/usr/lib64/qt5/mkspecs/common/gcc-base-unix.conf \
		/usr/lib64/qt5/mkspecs/common/g++-base.conf \
		/usr/lib64/qt5/mkspecs/common/g++-unix.conf \
		/usr/lib64/qt5/mkspecs/qconfig.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_Attica.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_Baloo.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_BluezQt.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_KActivities.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_KActivitiesStats.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_KArchive.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_KAuth.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_KBookmarks.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_KCMUtils.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_KCodecs.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_KCompletion.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_KConfigCore.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_KConfigGui.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_KConfigWidgets.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_KCoreAddons.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_KCrash.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_KDBusAddons.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_KDeclarative.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_KDESu.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_KDNSSD.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_KEmoticons.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_KFileMetaData.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_KGlobalAccel.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_KGuiAddons.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_KHolidays.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_KHtml.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_KI18n.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_KIconThemes.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_KIdleTime.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_KIOCore.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_KIOFileWidgets.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_KIOGui.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_KIOWidgets.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_Kirigami2.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_KItemModels.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_KItemViews.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_KJobWidgets.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_KJS.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_KJSApi.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_KJsEmbed.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_KNewStuff.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_KNewStuffCore.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_KNotifications.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_KNotifyConfig.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_KNTLM.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_KParts.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_KPeople.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_KPeopleWidgets.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_KPty.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_KrossCore.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_KrossUi.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_KRunner.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_KScreen.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_KService.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_KSyntaxHighlighting.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_KTextEditor.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_KTextWidgets.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_KUnitConversion.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_KWallet.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_KWaylandClient.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_KWaylandServer.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_KWidgetsAddons.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_KWindowSystem.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_KXmlGui.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_KXmlRpcClient.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_accessibility_support_private.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_bootstrap_private.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_concurrent.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_concurrent_private.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_core.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_core_private.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_dbus.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_dbus_private.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_designer.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_designer_private.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_designercomponents_private.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_devicediscovery_support_private.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_edid_support_private.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_egl_support_private.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_eventdispatcher_support_private.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_fb_support_private.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_fontdatabase_support_private.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_glx_support_private.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_gui.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_gui_private.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_hunspellinputmethod_private.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_linuxaccessibility_support_private.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_network.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_network_private.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_openglextensions.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_openglextensions_private.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_packetprotocol_private.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_platformcompositor_support_private.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_printsupport.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_printsupport_private.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_qml.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_qml_private.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_qmldebug_private.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_qmldevtools_private.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_qmltest.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_qmltest_private.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_quick.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_quick_private.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_quickcontrols2.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_quickcontrols2_private.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_quickparticles_private.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_quickshapes_private.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_quicktemplates2_private.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_quickwidgets.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_quickwidgets_private.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_script.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_script_private.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_scripttools.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_scripttools_private.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_sensors.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_sensors_private.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_service_support_private.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_sql.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_sql_private.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_svg.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_svg_private.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_testlib.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_testlib_private.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_theme_support_private.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_uiplugin.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_uitools.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_uitools_private.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_virtualkeyboard.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_virtualkeyboard_private.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_waylandclient.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_waylandclient_private.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_waylandcompositor.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_waylandcompositor_private.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_widgets.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_widgets_private.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_x11extras.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_x11extras_private.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_xcb_qpa_lib_private.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_xml.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_xml_private.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_xmlpatterns.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_lib_xmlpatterns_private.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_NetworkManagerQt.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_phonon4qt5.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_QuickAddons.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_Solid.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_SonnetCore.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_SonnetUi.pri \
		/usr/lib64/qt5/mkspecs/modules/qt_ThreadWeaver.pri \
		/usr/lib64/qt5/mkspecs/features/qt_functions.prf \
		/usr/lib64/qt5/mkspecs/features/qt_config.prf \
		/usr/lib64/qt5/mkspecs/linux-g++/qmake.conf \
		/usr/lib64/qt5/mkspecs/features/spec_post.prf \
		/usr/lib64/qt5/mkspecs/features/exclusive_builds.prf \
		/usr/lib64/qt5/mkspecs/features/toolchain.prf \
		/usr/lib64/qt5/mkspecs/features/default_pre.prf \
		/usr/lib64/qt5/mkspecs/features/resolve_config.prf \
		/usr/lib64/qt5/mkspecs/features/default_post.prf \
		/usr/lib64/qt5/mkspecs/features/warn_on.prf \
		/usr/lib64/qt5/mkspecs/features/qt.prf \
		/usr/lib64/qt5/mkspecs/features/resources.prf \
		/usr/lib64/qt5/mkspecs/features/moc.prf \
		/usr/lib64/qt5/mkspecs/features/unix/opengl.prf \
		/usr/lib64/qt5/mkspecs/features/uic.prf \
		/usr/lib64/qt5/mkspecs/features/unix/thread.prf \
		/usr/lib64/qt5/mkspecs/features/qmake_use.prf \
		/usr/lib64/qt5/mkspecs/features/file_copies.prf \
		/usr/lib64/qt5/mkspecs/features/testcase_targets.prf \
		/usr/lib64/qt5/mkspecs/features/exceptions.prf \
		/usr/lib64/qt5/mkspecs/features/yacc.prf \
		/usr/lib64/qt5/mkspecs/features/lex.prf \
		arduino_alarm_manager.pro \
		/usr/lib64/libQt5Widgets.prl \
		/usr/lib64/libQt5Gui.prl \
		/usr/lib64/libQt5Core.prl
	$(QMAKE) -o Makefile arduino_alarm_manager.pro
/usr/lib64/qt5/mkspecs/features/spec_pre.prf:
/usr/lib64/qt5/mkspecs/common/unix.conf:
/usr/lib64/qt5/mkspecs/common/linux.conf:
/usr/lib64/qt5/mkspecs/common/sanitize.conf:
/usr/lib64/qt5/mkspecs/common/gcc-base.conf:
/usr/lib64/qt5/mkspecs/common/gcc-base-unix.conf:
/usr/lib64/qt5/mkspecs/common/g++-base.conf:
/usr/lib64/qt5/mkspecs/common/g++-unix.conf:
/usr/lib64/qt5/mkspecs/qconfig.pri:
/usr/lib64/qt5/mkspecs/modules/qt_Attica.pri:
/usr/lib64/qt5/mkspecs/modules/qt_Baloo.pri:
/usr/lib64/qt5/mkspecs/modules/qt_BluezQt.pri:
/usr/lib64/qt5/mkspecs/modules/qt_KActivities.pri:
/usr/lib64/qt5/mkspecs/modules/qt_KActivitiesStats.pri:
/usr/lib64/qt5/mkspecs/modules/qt_KArchive.pri:
/usr/lib64/qt5/mkspecs/modules/qt_KAuth.pri:
/usr/lib64/qt5/mkspecs/modules/qt_KBookmarks.pri:
/usr/lib64/qt5/mkspecs/modules/qt_KCMUtils.pri:
/usr/lib64/qt5/mkspecs/modules/qt_KCodecs.pri:
/usr/lib64/qt5/mkspecs/modules/qt_KCompletion.pri:
/usr/lib64/qt5/mkspecs/modules/qt_KConfigCore.pri:
/usr/lib64/qt5/mkspecs/modules/qt_KConfigGui.pri:
/usr/lib64/qt5/mkspecs/modules/qt_KConfigWidgets.pri:
/usr/lib64/qt5/mkspecs/modules/qt_KCoreAddons.pri:
/usr/lib64/qt5/mkspecs/modules/qt_KCrash.pri:
/usr/lib64/qt5/mkspecs/modules/qt_KDBusAddons.pri:
/usr/lib64/qt5/mkspecs/modules/qt_KDeclarative.pri:
/usr/lib64/qt5/mkspecs/modules/qt_KDESu.pri:
/usr/lib64/qt5/mkspecs/modules/qt_KDNSSD.pri:
/usr/lib64/qt5/mkspecs/modules/qt_KEmoticons.pri:
/usr/lib64/qt5/mkspecs/modules/qt_KFileMetaData.pri:
/usr/lib64/qt5/mkspecs/modules/qt_KGlobalAccel.pri:
/usr/lib64/qt5/mkspecs/modules/qt_KGuiAddons.pri:
/usr/lib64/qt5/mkspecs/modules/qt_KHolidays.pri:
/usr/lib64/qt5/mkspecs/modules/qt_KHtml.pri:
/usr/lib64/qt5/mkspecs/modules/qt_KI18n.pri:
/usr/lib64/qt5/mkspecs/modules/qt_KIconThemes.pri:
/usr/lib64/qt5/mkspecs/modules/qt_KIdleTime.pri:
/usr/lib64/qt5/mkspecs/modules/qt_KIOCore.pri:
/usr/lib64/qt5/mkspecs/modules/qt_KIOFileWidgets.pri:
/usr/lib64/qt5/mkspecs/modules/qt_KIOGui.pri:
/usr/lib64/qt5/mkspecs/modules/qt_KIOWidgets.pri:
/usr/lib64/qt5/mkspecs/modules/qt_Kirigami2.pri:
/usr/lib64/qt5/mkspecs/modules/qt_KItemModels.pri:
/usr/lib64/qt5/mkspecs/modules/qt_KItemViews.pri:
/usr/lib64/qt5/mkspecs/modules/qt_KJobWidgets.pri:
/usr/lib64/qt5/mkspecs/modules/qt_KJS.pri:
/usr/lib64/qt5/mkspecs/modules/qt_KJSApi.pri:
/usr/lib64/qt5/mkspecs/modules/qt_KJsEmbed.pri:
/usr/lib64/qt5/mkspecs/modules/qt_KNewStuff.pri:
/usr/lib64/qt5/mkspecs/modules/qt_KNewStuffCore.pri:
/usr/lib64/qt5/mkspecs/modules/qt_KNotifications.pri:
/usr/lib64/qt5/mkspecs/modules/qt_KNotifyConfig.pri:
/usr/lib64/qt5/mkspecs/modules/qt_KNTLM.pri:
/usr/lib64/qt5/mkspecs/modules/qt_KParts.pri:
/usr/lib64/qt5/mkspecs/modules/qt_KPeople.pri:
/usr/lib64/qt5/mkspecs/modules/qt_KPeopleWidgets.pri:
/usr/lib64/qt5/mkspecs/modules/qt_KPty.pri:
/usr/lib64/qt5/mkspecs/modules/qt_KrossCore.pri:
/usr/lib64/qt5/mkspecs/modules/qt_KrossUi.pri:
/usr/lib64/qt5/mkspecs/modules/qt_KRunner.pri:
/usr/lib64/qt5/mkspecs/modules/qt_KScreen.pri:
/usr/lib64/qt5/mkspecs/modules/qt_KService.pri:
/usr/lib64/qt5/mkspecs/modules/qt_KSyntaxHighlighting.pri:
/usr/lib64/qt5/mkspecs/modules/qt_KTextEditor.pri:
/usr/lib64/qt5/mkspecs/modules/qt_KTextWidgets.pri:
/usr/lib64/qt5/mkspecs/modules/qt_KUnitConversion.pri:
/usr/lib64/qt5/mkspecs/modules/qt_KWallet.pri:
/usr/lib64/qt5/mkspecs/modules/qt_KWaylandClient.pri:
/usr/lib64/qt5/mkspecs/modules/qt_KWaylandServer.pri:
/usr/lib64/qt5/mkspecs/modules/qt_KWidgetsAddons.pri:
/usr/lib64/qt5/mkspecs/modules/qt_KWindowSystem.pri:
/usr/lib64/qt5/mkspecs/modules/qt_KXmlGui.pri:
/usr/lib64/qt5/mkspecs/modules/qt_KXmlRpcClient.pri:
/usr/lib64/qt5/mkspecs/modules/qt_lib_accessibility_support_private.pri:
/usr/lib64/qt5/mkspecs/modules/qt_lib_bootstrap_private.pri:
/usr/lib64/qt5/mkspecs/modules/qt_lib_concurrent.pri:
/usr/lib64/qt5/mkspecs/modules/qt_lib_concurrent_private.pri:
/usr/lib64/qt5/mkspecs/modules/qt_lib_core.pri:
/usr/lib64/qt5/mkspecs/modules/qt_lib_core_private.pri:
/usr/lib64/qt5/mkspecs/modules/qt_lib_dbus.pri:
/usr/lib64/qt5/mkspecs/modules/qt_lib_dbus_private.pri:
/usr/lib64/qt5/mkspecs/modules/qt_lib_designer.pri:
/usr/lib64/qt5/mkspecs/modules/qt_lib_designer_private.pri:
/usr/lib64/qt5/mkspecs/modules/qt_lib_designercomponents_private.pri:
/usr/lib64/qt5/mkspecs/modules/qt_lib_devicediscovery_support_private.pri:
/usr/lib64/qt5/mkspecs/modules/qt_lib_edid_support_private.pri:
/usr/lib64/qt5/mkspecs/modules/qt_lib_egl_support_private.pri:
/usr/lib64/qt5/mkspecs/modules/qt_lib_eventdispatcher_support_private.pri:
/usr/lib64/qt5/mkspecs/modules/qt_lib_fb_support_private.pri:
/usr/lib64/qt5/mkspecs/modules/qt_lib_fontdatabase_support_private.pri:
/usr/lib64/qt5/mkspecs/modules/qt_lib_glx_support_private.pri:
/usr/lib64/qt5/mkspecs/modules/qt_lib_gui.pri:
/usr/lib64/qt5/mkspecs/modules/qt_lib_gui_private.pri:
/usr/lib64/qt5/mkspecs/modules/qt_lib_hunspellinputmethod_private.pri:
/usr/lib64/qt5/mkspecs/modules/qt_lib_linuxaccessibility_support_private.pri:
/usr/lib64/qt5/mkspecs/modules/qt_lib_network.pri:
/usr/lib64/qt5/mkspecs/modules/qt_lib_network_private.pri:
/usr/lib64/qt5/mkspecs/modules/qt_lib_openglextensions.pri:
/usr/lib64/qt5/mkspecs/modules/qt_lib_openglextensions_private.pri:
/usr/lib64/qt5/mkspecs/modules/qt_lib_packetprotocol_private.pri:
/usr/lib64/qt5/mkspecs/modules/qt_lib_platformcompositor_support_private.pri:
/usr/lib64/qt5/mkspecs/modules/qt_lib_printsupport.pri:
/usr/lib64/qt5/mkspecs/modules/qt_lib_printsupport_private.pri:
/usr/lib64/qt5/mkspecs/modules/qt_lib_qml.pri:
/usr/lib64/qt5/mkspecs/modules/qt_lib_qml_private.pri:
/usr/lib64/qt5/mkspecs/modules/qt_lib_qmldebug_private.pri:
/usr/lib64/qt5/mkspecs/modules/qt_lib_qmldevtools_private.pri:
/usr/lib64/qt5/mkspecs/modules/qt_lib_qmltest.pri:
/usr/lib64/qt5/mkspecs/modules/qt_lib_qmltest_private.pri:
/usr/lib64/qt5/mkspecs/modules/qt_lib_quick.pri:
/usr/lib64/qt5/mkspecs/modules/qt_lib_quick_private.pri:
/usr/lib64/qt5/mkspecs/modules/qt_lib_quickcontrols2.pri:
/usr/lib64/qt5/mkspecs/modules/qt_lib_quickcontrols2_private.pri:
/usr/lib64/qt5/mkspecs/modules/qt_lib_quickparticles_private.pri:
/usr/lib64/qt5/mkspecs/modules/qt_lib_quickshapes_private.pri:
/usr/lib64/qt5/mkspecs/modules/qt_lib_quicktemplates2_private.pri:
/usr/lib64/qt5/mkspecs/modules/qt_lib_quickwidgets.pri:
/usr/lib64/qt5/mkspecs/modules/qt_lib_quickwidgets_private.pri:
/usr/lib64/qt5/mkspecs/modules/qt_lib_script.pri:
/usr/lib64/qt5/mkspecs/modules/qt_lib_script_private.pri:
/usr/lib64/qt5/mkspecs/modules/qt_lib_scripttools.pri:
/usr/lib64/qt5/mkspecs/modules/qt_lib_scripttools_private.pri:
/usr/lib64/qt5/mkspecs/modules/qt_lib_sensors.pri:
/usr/lib64/qt5/mkspecs/modules/qt_lib_sensors_private.pri:
/usr/lib64/qt5/mkspecs/modules/qt_lib_service_support_private.pri:
/usr/lib64/qt5/mkspecs/modules/qt_lib_sql.pri:
/usr/lib64/qt5/mkspecs/modules/qt_lib_sql_private.pri:
/usr/lib64/qt5/mkspecs/modules/qt_lib_svg.pri:
/usr/lib64/qt5/mkspecs/modules/qt_lib_svg_private.pri:
/usr/lib64/qt5/mkspecs/modules/qt_lib_testlib.pri:
/usr/lib64/qt5/mkspecs/modules/qt_lib_testlib_private.pri:
/usr/lib64/qt5/mkspecs/modules/qt_lib_theme_support_private.pri:
/usr/lib64/qt5/mkspecs/modules/qt_lib_uiplugin.pri:
/usr/lib64/qt5/mkspecs/modules/qt_lib_uitools.pri:
/usr/lib64/qt5/mkspecs/modules/qt_lib_uitools_private.pri:
/usr/lib64/qt5/mkspecs/modules/qt_lib_virtualkeyboard.pri:
/usr/lib64/qt5/mkspecs/modules/qt_lib_virtualkeyboard_private.pri:
/usr/lib64/qt5/mkspecs/modules/qt_lib_waylandclient.pri:
/usr/lib64/qt5/mkspecs/modules/qt_lib_waylandclient_private.pri:
/usr/lib64/qt5/mkspecs/modules/qt_lib_waylandcompositor.pri:
/usr/lib64/qt5/mkspecs/modules/qt_lib_waylandcompositor_private.pri:
/usr/lib64/qt5/mkspecs/modules/qt_lib_widgets.pri:
/usr/lib64/qt5/mkspecs/modules/qt_lib_widgets_private.pri:
/usr/lib64/qt5/mkspecs/modules/qt_lib_x11extras.pri:
/usr/lib64/qt5/mkspecs/modules/qt_lib_x11extras_private.pri:
/usr/lib64/qt5/mkspecs/modules/qt_lib_xcb_qpa_lib_private.pri:
/usr/lib64/qt5/mkspecs/modules/qt_lib_xml.pri:
/usr/lib64/qt5/mkspecs/modules/qt_lib_xml_private.pri:
/usr/lib64/qt5/mkspecs/modules/qt_lib_xmlpatterns.pri:
/usr/lib64/qt5/mkspecs/modules/qt_lib_xmlpatterns_private.pri:
/usr/lib64/qt5/mkspecs/modules/qt_NetworkManagerQt.pri:
/usr/lib64/qt5/mkspecs/modules/qt_phonon4qt5.pri:
/usr/lib64/qt5/mkspecs/modules/qt_QuickAddons.pri:
/usr/lib64/qt5/mkspecs/modules/qt_Solid.pri:
/usr/lib64/qt5/mkspecs/modules/qt_SonnetCore.pri:
/usr/lib64/qt5/mkspecs/modules/qt_SonnetUi.pri:
/usr/lib64/qt5/mkspecs/modules/qt_ThreadWeaver.pri:
/usr/lib64/qt5/mkspecs/features/qt_functions.prf:
/usr/lib64/qt5/mkspecs/features/qt_config.prf:
/usr/lib64/qt5/mkspecs/linux-g++/qmake.conf:
/usr/lib64/qt5/mkspecs/features/spec_post.prf:
/usr/lib64/qt5/mkspecs/features/exclusive_builds.prf:
/usr/lib64/qt5/mkspecs/features/toolchain.prf:
/usr/lib64/qt5/mkspecs/features/default_pre.prf:
/usr/lib64/qt5/mkspecs/features/resolve_config.prf:
/usr/lib64/qt5/mkspecs/features/default_post.prf:
/usr/lib64/qt5/mkspecs/features/warn_on.prf:
/usr/lib64/qt5/mkspecs/features/qt.prf:
/usr/lib64/qt5/mkspecs/features/resources.prf:
/usr/lib64/qt5/mkspecs/features/moc.prf:
/usr/lib64/qt5/mkspecs/features/unix/opengl.prf:
/usr/lib64/qt5/mkspecs/features/uic.prf:
/usr/lib64/qt5/mkspecs/features/unix/thread.prf:
/usr/lib64/qt5/mkspecs/features/qmake_use.prf:
/usr/lib64/qt5/mkspecs/features/file_copies.prf:
/usr/lib64/qt5/mkspecs/features/testcase_targets.prf:
/usr/lib64/qt5/mkspecs/features/exceptions.prf:
/usr/lib64/qt5/mkspecs/features/yacc.prf:
/usr/lib64/qt5/mkspecs/features/lex.prf:
arduino_alarm_manager.pro:
/usr/lib64/libQt5Widgets.prl:
/usr/lib64/libQt5Gui.prl:
/usr/lib64/libQt5Core.prl:
qmake: FORCE
	@$(QMAKE) -o Makefile arduino_alarm_manager.pro

qmake_all: FORCE


all: Makefile arduino_alarm_manager

dist: distdir FORCE
	(cd `dirname $(DISTDIR)` && $(TAR) $(DISTNAME).tar $(DISTNAME) && $(COMPRESS) $(DISTNAME).tar) && $(MOVE) `dirname $(DISTDIR)`/$(DISTNAME).tar.gz . && $(DEL_FILE) -r $(DISTDIR)

distdir: FORCE
	@test -d $(DISTDIR) || mkdir -p $(DISTDIR)
	$(COPY_FILE) --parents $(DIST) $(DISTDIR)/
	$(COPY_FILE) --parents /usr/lib64/qt5/mkspecs/features/data/dummy.cpp $(DISTDIR)/
	$(COPY_FILE) --parents arduino_alarm_manager.cc $(DISTDIR)/


clean: compiler_clean 
	-$(DEL_FILE) $(OBJECTS)
	-$(DEL_FILE) *~ core *.core


distclean: clean 
	-$(DEL_FILE) $(TARGET) 
	-$(DEL_FILE) .qmake.stash
	-$(DEL_FILE) Makefile


####### Sub-libraries

mocclean: compiler_moc_header_clean compiler_moc_objc_header_clean compiler_moc_source_clean

mocables: compiler_moc_header_make_all compiler_moc_objc_header_make_all compiler_moc_source_make_all

check: first

benchmark: first

compiler_rcc_make_all:
compiler_rcc_clean:
compiler_moc_predefs_make_all: moc_predefs.h
compiler_moc_predefs_clean:
	-$(DEL_FILE) moc_predefs.h
moc_predefs.h: /usr/lib64/qt5/mkspecs/features/data/dummy.cpp
	g++ -pipe -O2 -Wall -W -dM -E -o moc_predefs.h /usr/lib64/qt5/mkspecs/features/data/dummy.cpp

compiler_moc_header_make_all:
compiler_moc_header_clean:
compiler_moc_objc_header_make_all:
compiler_moc_objc_header_clean:
compiler_moc_source_make_all:
compiler_moc_source_clean:
compiler_uic_make_all:
compiler_uic_clean:
compiler_yacc_decl_make_all:
compiler_yacc_decl_clean:
compiler_yacc_impl_make_all:
compiler_yacc_impl_clean:
compiler_lex_make_all:
compiler_lex_clean:
compiler_clean: compiler_moc_predefs_clean 

####### Compile

arduino_alarm_manager.o: arduino_alarm_manager.cc libs/bluetooth_unix.hpp \
		libs/bluetooth_windows.hpp
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o arduino_alarm_manager.o arduino_alarm_manager.cc

####### Install

install:  FORCE

uninstall:  FORCE

FORCE:

