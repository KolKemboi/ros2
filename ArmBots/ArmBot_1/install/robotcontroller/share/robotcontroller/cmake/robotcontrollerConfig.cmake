# generated from ament/cmake/core/templates/nameConfig.cmake.in

# prevent multiple inclusion
if(_robotcontroller_CONFIG_INCLUDED)
  # ensure to keep the found flag the same
  if(NOT DEFINED robotcontroller_FOUND)
    # explicitly set it to FALSE, otherwise CMake will set it to TRUE
    set(robotcontroller_FOUND FALSE)
  elseif(NOT robotcontroller_FOUND)
    # use separate condition to avoid uninitialized variable warning
    set(robotcontroller_FOUND FALSE)
  endif()
  return()
endif()
set(_robotcontroller_CONFIG_INCLUDED TRUE)

# output package information
if(NOT robotcontroller_FIND_QUIETLY)
  message(STATUS "Found robotcontroller: 0.0.0 (${robotcontroller_DIR})")
endif()

# warn when using a deprecated package
if(NOT "" STREQUAL "")
  set(_msg "Package 'robotcontroller' is deprecated")
  # append custom deprecation text if available
  if(NOT "" STREQUAL "TRUE")
    set(_msg "${_msg} ()")
  endif()
  # optionally quiet the deprecation message
  if(NOT ${robotcontroller_DEPRECATED_QUIET})
    message(DEPRECATION "${_msg}")
  endif()
endif()

# flag package as ament-based to distinguish it after being find_package()-ed
set(robotcontroller_FOUND_AMENT_PACKAGE TRUE)

# include all config extra files
set(_extras "")
foreach(_extra ${_extras})
  include("${robotcontroller_DIR}/${_extra}")
endforeach()
