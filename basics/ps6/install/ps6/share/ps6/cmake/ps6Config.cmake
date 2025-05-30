# generated from ament/cmake/core/templates/nameConfig.cmake.in

# prevent multiple inclusion
if(_ps6_CONFIG_INCLUDED)
  # ensure to keep the found flag the same
  if(NOT DEFINED ps6_FOUND)
    # explicitly set it to FALSE, otherwise CMake will set it to TRUE
    set(ps6_FOUND FALSE)
  elseif(NOT ps6_FOUND)
    # use separate condition to avoid uninitialized variable warning
    set(ps6_FOUND FALSE)
  endif()
  return()
endif()
set(_ps6_CONFIG_INCLUDED TRUE)

# output package information
if(NOT ps6_FIND_QUIETLY)
  message(STATUS "Found ps6: 0.0.0 (${ps6_DIR})")
endif()

# warn when using a deprecated package
if(NOT "" STREQUAL "")
  set(_msg "Package 'ps6' is deprecated")
  # append custom deprecation text if available
  if(NOT "" STREQUAL "TRUE")
    set(_msg "${_msg} ()")
  endif()
  # optionally quiet the deprecation message
  if(NOT ${ps6_DEPRECATED_QUIET})
    message(DEPRECATION "${_msg}")
  endif()
endif()

# flag package as ament-based to distinguish it after being find_package()-ed
set(ps6_FOUND_AMENT_PACKAGE TRUE)

# include all config extra files
set(_extras "")
foreach(_extra ${_extras})
  include("${ps6_DIR}/${_extra}")
endforeach()
