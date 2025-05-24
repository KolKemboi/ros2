# generated from ament/cmake/core/templates/nameConfig.cmake.in

# prevent multiple inclusion
if(_ps4_CONFIG_INCLUDED)
  # ensure to keep the found flag the same
  if(NOT DEFINED ps4_FOUND)
    # explicitly set it to FALSE, otherwise CMake will set it to TRUE
    set(ps4_FOUND FALSE)
  elseif(NOT ps4_FOUND)
    # use separate condition to avoid uninitialized variable warning
    set(ps4_FOUND FALSE)
  endif()
  return()
endif()
set(_ps4_CONFIG_INCLUDED TRUE)

# output package information
if(NOT ps4_FIND_QUIETLY)
  message(STATUS "Found ps4: 0.0.0 (${ps4_DIR})")
endif()

# warn when using a deprecated package
if(NOT "" STREQUAL "")
  set(_msg "Package 'ps4' is deprecated")
  # append custom deprecation text if available
  if(NOT "" STREQUAL "TRUE")
    set(_msg "${_msg} ()")
  endif()
  # optionally quiet the deprecation message
  if(NOT ${ps4_DEPRECATED_QUIET})
    message(DEPRECATION "${_msg}")
  endif()
endif()

# flag package as ament-based to distinguish it after being find_package()-ed
set(ps4_FOUND_AMENT_PACKAGE TRUE)

# include all config extra files
set(_extras "")
foreach(_extra ${_extras})
  include("${ps4_DIR}/${_extra}")
endforeach()
