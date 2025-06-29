# generated from ament/cmake/core/templates/nameConfig.cmake.in

# prevent multiple inclusion
if(_boilerplate_cfg2_CONFIG_INCLUDED)
  # ensure to keep the found flag the same
  if(NOT DEFINED boilerplate_cfg2_FOUND)
    # explicitly set it to FALSE, otherwise CMake will set it to TRUE
    set(boilerplate_cfg2_FOUND FALSE)
  elseif(NOT boilerplate_cfg2_FOUND)
    # use separate condition to avoid uninitialized variable warning
    set(boilerplate_cfg2_FOUND FALSE)
  endif()
  return()
endif()
set(_boilerplate_cfg2_CONFIG_INCLUDED TRUE)

# output package information
if(NOT boilerplate_cfg2_FIND_QUIETLY)
  message(STATUS "Found boilerplate_cfg2: 0.3.0 (${boilerplate_cfg2_DIR})")
endif()

# warn when using a deprecated package
if(NOT "" STREQUAL "")
  set(_msg "Package 'boilerplate_cfg2' is deprecated")
  # append custom deprecation text if available
  if(NOT "" STREQUAL "TRUE")
    set(_msg "${_msg} ()")
  endif()
  # optionally quiet the deprecation message
  if(NOT ${boilerplate_cfg2_DEPRECATED_QUIET})
    message(DEPRECATION "${_msg}")
  endif()
endif()

# flag package as ament-based to distinguish it after being find_package()-ed
set(boilerplate_cfg2_FOUND_AMENT_PACKAGE TRUE)

# include all config extra files
set(_extras "")
foreach(_extra ${_extras})
  include("${boilerplate_cfg2_DIR}/${_extra}")
endforeach()
