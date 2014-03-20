include_directories(
  ${Boost_INCLUDE_DIRS}
  ${cpp-netlib_INCLUDE_DIRS}
  ${OPENSSL_INCLUDE_DIR}
)
link_directories(
  ${Boost_LIBRARY_DIRS}
  ${cpp-netlib_LIBRARY_DIRS}
)

aux_source_directory("." SOURCES)

add_executable(fetch ${SOURCES})
add_dependencies(fetch cpp-netlib)
target_link_libraries(fetch ${Boost_LIBRARIES} ${cpp-netlib_LIBRARIES} ${OPENSSL_LIBRARIES} ${ICU_LIBRARIES} ${ICU_I18N_LIBRARIES})
