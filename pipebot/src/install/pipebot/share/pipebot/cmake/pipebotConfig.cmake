# generated from ament/cmake/core/templates/nameConfig.cmake.in

# prevent multiple inclusion
if(_pipebot_CONFIG_INCLUDED)
  # ensure to keep the found flag the same
  if(NOT DEFINED pipebot_FOUND)
    # explicitly set it to FALSE, otherwise CMake will set it to TRUE
    set(pipebot_FOUND FALSE)
  elseif(NOT pipebot_FOUND)
    # use separate condition to avoid uninitialized variable warning
    set(pipebot_FOUND FALSE)
  endif()
  return()
endif()
set(_pipebot_CONFIG_INCLUDED TRUE)

# output package information
if(NOT pipebot_FIND_QUIETLY)
  message(STATUS "Found pipebot: 0.0.0 (${pipebot_DIR})")
endif()

# warn when using a deprecated package
if(NOT "" STREQUAL "")
  set(_msg "Package 'pipebot' is deprecated")
  # append custom deprecation text if available
  if(NOT "" STREQUAL "TRUE")
    set(_msg "${_msg} ()")
  endif()
  # optionally quiet the deprecation message
  if(NOT ${pipebot_DEPRECATED_QUIET})
    message(DEPRECATION "${_msg}")
  endif()
endif()

# flag package as ament-based to distinguish it after being find_package()-ed
set(pipebot_FOUND_AMENT_PACKAGE TRUE)

# include all config extra files
set(_extras "")
foreach(_extra ${_extras})
  include("${pipebot_DIR}/${_extra}")
endforeach()
