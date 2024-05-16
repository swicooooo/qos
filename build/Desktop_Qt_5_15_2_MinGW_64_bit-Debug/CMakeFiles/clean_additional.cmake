# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\qosbrowser_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\qosbrowser_autogen.dir\\ParseCache.txt"
  "qosbrowser_autogen"
  )
endif()
