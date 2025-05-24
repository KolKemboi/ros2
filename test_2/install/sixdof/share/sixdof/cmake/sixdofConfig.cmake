# generated from ament/cmake/core/templates/nameConfig.cmake.in

# prevent multiple inclusion
if(_sixdof_CONFIG_INCLUDED)
  # ensure to keep the found flag the same
  if(NOT DEFINED sixdof_FOUND)
    # explicitly set it to FALSE, otherwise CMake will set it to TRUE
    set(sixdof_FOUND FALSE)
  elseif(NOT sixdof_FOUND)
    # use separate condition to avoid uninitialized variable warning
    set(sixdof_FOUND FALSE)
  endif()
  return()
endif()
set(_sixdof_CONFIG_INCLUDED TRUE)

# output package information
if(NOT sixdof_FIND_QUIETLY)
  message(STATUS "Found sixdof: 0.0.0 (${sixdof_DIR})")
endif()

# warn when using a deprecated package
if(NOT "" STREQUAL "")
  set(_msg "Package 'sixdof' is deprecated")
  # append custom deprecation text if available
  if(NOT "" STREQUAL "TRUE")
    set(_msg "${_msg} ()")
  endif()
  # optionally quiet the deprecation message
  if(NOT ${sixdof_DEPRECATED_QUIET})
    message(DEPRECATION "${_msg}")
  endif()
endif()

# flag package as ament-based to distinguish it after being find_package()-ed
set(sixdof_FOUND_AMENT_PACKAGE TRUE)

# include all config extra files
set(_extras "")
foreach(_extra ${_extras})
  include("${sixdof_DIR}/${_extra}")
endforeach()
