# generated from ament/cmake/core/templates/nameConfig.cmake.in

# prevent multiple inclusion
if(_raceteam_hw_CONFIG_INCLUDED)
  # ensure to keep the found flag the same
  if(NOT DEFINED raceteam_hw_FOUND)
    # explicitly set it to FALSE, otherwise CMake will set it to TRUE
    set(raceteam_hw_FOUND FALSE)
  elseif(NOT raceteam_hw_FOUND)
    # use separate condition to avoid uninitialized variable warning
    set(raceteam_hw_FOUND FALSE)
  endif()
  return()
endif()
set(_raceteam_hw_CONFIG_INCLUDED TRUE)

# output package information
if(NOT raceteam_hw_FIND_QUIETLY)
  message(STATUS "Found raceteam_hw: 0.0.0 (${raceteam_hw_DIR})")
endif()

# warn when using a deprecated package
if(NOT "" STREQUAL "")
  set(_msg "Package 'raceteam_hw' is deprecated")
  # append custom deprecation text if available
  if(NOT "" STREQUAL "TRUE")
    set(_msg "${_msg} ()")
  endif()
  # optionally quiet the deprecation message
  if(NOT raceteam_hw_DEPRECATED_QUIET)
    message(DEPRECATION "${_msg}")
  endif()
endif()

# flag package as ament-based to distinguish it after being find_package()-ed
set(raceteam_hw_FOUND_AMENT_PACKAGE TRUE)

# include all config extra files
set(_extras "")
foreach(_extra ${_extras})
  include("${raceteam_hw_DIR}/${_extra}")
endforeach()
