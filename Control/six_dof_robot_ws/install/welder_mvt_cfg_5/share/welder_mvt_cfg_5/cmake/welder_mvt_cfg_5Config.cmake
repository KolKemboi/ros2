# generated from ament/cmake/core/templates/nameConfig.cmake.in

# prevent multiple inclusion
if(_welder_mvt_cfg_5_CONFIG_INCLUDED)
  # ensure to keep the found flag the same
  if(NOT DEFINED welder_mvt_cfg_5_FOUND)
    # explicitly set it to FALSE, otherwise CMake will set it to TRUE
    set(welder_mvt_cfg_5_FOUND FALSE)
  elseif(NOT welder_mvt_cfg_5_FOUND)
    # use separate condition to avoid uninitialized variable warning
    set(welder_mvt_cfg_5_FOUND FALSE)
  endif()
  return()
endif()
set(_welder_mvt_cfg_5_CONFIG_INCLUDED TRUE)

# output package information
if(NOT welder_mvt_cfg_5_FIND_QUIETLY)
  message(STATUS "Found welder_mvt_cfg_5: 0.3.0 (${welder_mvt_cfg_5_DIR})")
endif()

# warn when using a deprecated package
if(NOT "" STREQUAL "")
  set(_msg "Package 'welder_mvt_cfg_5' is deprecated")
  # append custom deprecation text if available
  if(NOT "" STREQUAL "TRUE")
    set(_msg "${_msg} ()")
  endif()
  # optionally quiet the deprecation message
  if(NOT ${welder_mvt_cfg_5_DEPRECATED_QUIET})
    message(DEPRECATION "${_msg}")
  endif()
endif()

# flag package as ament-based to distinguish it after being find_package()-ed
set(welder_mvt_cfg_5_FOUND_AMENT_PACKAGE TRUE)

# include all config extra files
set(_extras "")
foreach(_extra ${_extras})
  include("${welder_mvt_cfg_5_DIR}/${_extra}")
endforeach()
