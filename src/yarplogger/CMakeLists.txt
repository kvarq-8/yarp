if(CREATE_YARPLOGGER)

  project(yarplogger)

  include(YarpUseQt5)
  include(YarpOSXUtilities)

  get_property(YARP_TREE_INCLUDE_DIRS TARGET YARP_OS PROPERTY INCLUDE_DIRS)
  get_property(YARP_OS_INCLUDE_DIRS TARGET YARP_OS PROPERTY INCLUDE_DIRS)
  get_property(YARP_logger_HDRS TARGET YARP_logger PROPERTY INCLUDE_DIRS)
  include_directories(${YARP_OS_INCLUDE_DIRS} ${YARP_logger_HDRS})
  set(CMAKE_INCLUDE_CURRENT_DIR TRUE)

  file(GLOB yarplogger_SRCS *.cpp)
  file(GLOB yarplogger_HDRS *.h)
  file(GLOB yarplogger_QRC_FILES *.qrc)
  file(GLOB yarplogger_UI_FILES *.ui)

  qt5_add_resources(yarplogger_QRC_GEN_SRCS ${yarplogger_QRC_FILES})
  qt5_wrap_ui(yarplogger_UI_GEN_SRCS ${yarplogger_UI_FILES})

  include_directories(${YARP_TREE_INCLUDE_DIRS})

  source_group(TREE "${CMAKE_CURRENT_SOURCE_DIR}"
               PREFIX "Source Files"
               FILES ${yarplogger_SRCS})
  source_group(TREE "${CMAKE_CURRENT_SOURCE_DIR}"
               PREFIX "Header Files"
               FILES ${yarplogger_HDRS})
  source_group("Resources Files" FILES ${yarplogger_QRC_FILES})
  source_group("UI Files" FILES ${yarplogger_UI_FILES})
  source_group("Generated Files" FILES ${yarplogger_QRC_GEN_SRCS}
                                       ${yarplogger_UI_GEN_SRCS})

  add_executable(yarplogger WIN32 ${yarplogger_SRCS}
                                  ${yarplogger_HDRS}
                                  ${yarplogger_QRC_FILES}
                                  ${yarplogger_QRC_GEN_SRCS}
                                  ${yarplogger_UI_FILES}
                                  ${yarplogger_UI_GEN_SRCS})

  target_link_libraries(yarplogger YARP_OS
                                   YARP_init
                                   YARP_logger
                                   Qt5::Widgets
                                   Qt5::Gui)

  install(TARGETS yarplogger
          COMPONENT utilities
          DESTINATION ${CMAKE_INSTALL_BINDIR})

  set_property(TARGET yarplogger PROPERTY FOLDER "Graphical User Interfaces")

  yarp_osx_duplicate_and_add_bundle(TARGET yarplogger
                                    INSTALL_COMPONENT utilities
                                    INSTALL_DESTINATION "${CMAKE_INSTALL_BINDIR}")

endif()
