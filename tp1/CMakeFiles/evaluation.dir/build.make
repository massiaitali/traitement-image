# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.9

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/local/Cellar/cmake/3.9.2/bin/cmake

# The command to remove a file.
RM = /usr/local/Cellar/cmake/3.9.2/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/carolineeche/Desktop/Massi/Traitement_image/tp1

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/carolineeche/Desktop/Massi/Traitement_image/tp1

# Include any dependencies generated for this target.
include CMakeFiles/evaluation.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/evaluation.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/evaluation.dir/flags.make

CMakeFiles/evaluation.dir/evaluation.cpp.o: CMakeFiles/evaluation.dir/flags.make
CMakeFiles/evaluation.dir/evaluation.cpp.o: evaluation.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/carolineeche/Desktop/Massi/Traitement_image/tp1/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/evaluation.dir/evaluation.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/evaluation.dir/evaluation.cpp.o -c /Users/carolineeche/Desktop/Massi/Traitement_image/tp1/evaluation.cpp

CMakeFiles/evaluation.dir/evaluation.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/evaluation.dir/evaluation.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/carolineeche/Desktop/Massi/Traitement_image/tp1/evaluation.cpp > CMakeFiles/evaluation.dir/evaluation.cpp.i

CMakeFiles/evaluation.dir/evaluation.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/evaluation.dir/evaluation.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/carolineeche/Desktop/Massi/Traitement_image/tp1/evaluation.cpp -o CMakeFiles/evaluation.dir/evaluation.cpp.s

CMakeFiles/evaluation.dir/evaluation.cpp.o.requires:

.PHONY : CMakeFiles/evaluation.dir/evaluation.cpp.o.requires

CMakeFiles/evaluation.dir/evaluation.cpp.o.provides: CMakeFiles/evaluation.dir/evaluation.cpp.o.requires
	$(MAKE) -f CMakeFiles/evaluation.dir/build.make CMakeFiles/evaluation.dir/evaluation.cpp.o.provides.build
.PHONY : CMakeFiles/evaluation.dir/evaluation.cpp.o.provides

CMakeFiles/evaluation.dir/evaluation.cpp.o.provides.build: CMakeFiles/evaluation.dir/evaluation.cpp.o


# Object files for target evaluation
evaluation_OBJECTS = \
"CMakeFiles/evaluation.dir/evaluation.cpp.o"

# External object files for target evaluation
evaluation_EXTERNAL_OBJECTS =

bin/evaluation: CMakeFiles/evaluation.dir/evaluation.cpp.o
bin/evaluation: CMakeFiles/evaluation.dir/build.make
bin/evaluation: /usr/local/lib/libopencv_stitching.3.3.0.dylib
bin/evaluation: /usr/local/lib/libopencv_superres.3.3.0.dylib
bin/evaluation: /usr/local/lib/libopencv_videostab.3.3.0.dylib
bin/evaluation: /usr/local/lib/libopencv_aruco.3.3.0.dylib
bin/evaluation: /usr/local/lib/libopencv_bgsegm.3.3.0.dylib
bin/evaluation: /usr/local/lib/libopencv_bioinspired.3.3.0.dylib
bin/evaluation: /usr/local/lib/libopencv_ccalib.3.3.0.dylib
bin/evaluation: /usr/local/lib/libopencv_dpm.3.3.0.dylib
bin/evaluation: /usr/local/lib/libopencv_face.3.3.0.dylib
bin/evaluation: /usr/local/lib/libopencv_fuzzy.3.3.0.dylib
bin/evaluation: /usr/local/lib/libopencv_img_hash.3.3.0.dylib
bin/evaluation: /usr/local/lib/libopencv_line_descriptor.3.3.0.dylib
bin/evaluation: /usr/local/lib/libopencv_optflow.3.3.0.dylib
bin/evaluation: /usr/local/lib/libopencv_reg.3.3.0.dylib
bin/evaluation: /usr/local/lib/libopencv_rgbd.3.3.0.dylib
bin/evaluation: /usr/local/lib/libopencv_saliency.3.3.0.dylib
bin/evaluation: /usr/local/lib/libopencv_stereo.3.3.0.dylib
bin/evaluation: /usr/local/lib/libopencv_structured_light.3.3.0.dylib
bin/evaluation: /usr/local/lib/libopencv_surface_matching.3.3.0.dylib
bin/evaluation: /usr/local/lib/libopencv_tracking.3.3.0.dylib
bin/evaluation: /usr/local/lib/libopencv_xfeatures2d.3.3.0.dylib
bin/evaluation: /usr/local/lib/libopencv_ximgproc.3.3.0.dylib
bin/evaluation: /usr/local/lib/libopencv_xobjdetect.3.3.0.dylib
bin/evaluation: /usr/local/lib/libopencv_xphoto.3.3.0.dylib
bin/evaluation: /usr/local/lib/libopencv_shape.3.3.0.dylib
bin/evaluation: /usr/local/lib/libopencv_photo.3.3.0.dylib
bin/evaluation: /usr/local/lib/libopencv_calib3d.3.3.0.dylib
bin/evaluation: /usr/local/lib/libopencv_phase_unwrapping.3.3.0.dylib
bin/evaluation: /usr/local/lib/libopencv_dnn.3.3.0.dylib
bin/evaluation: /usr/local/lib/libopencv_video.3.3.0.dylib
bin/evaluation: /usr/local/lib/libopencv_datasets.3.3.0.dylib
bin/evaluation: /usr/local/lib/libopencv_plot.3.3.0.dylib
bin/evaluation: /usr/local/lib/libopencv_text.3.3.0.dylib
bin/evaluation: /usr/local/lib/libopencv_features2d.3.3.0.dylib
bin/evaluation: /usr/local/lib/libopencv_flann.3.3.0.dylib
bin/evaluation: /usr/local/lib/libopencv_highgui.3.3.0.dylib
bin/evaluation: /usr/local/lib/libopencv_ml.3.3.0.dylib
bin/evaluation: /usr/local/lib/libopencv_videoio.3.3.0.dylib
bin/evaluation: /usr/local/lib/libopencv_imgcodecs.3.3.0.dylib
bin/evaluation: /usr/local/lib/libopencv_objdetect.3.3.0.dylib
bin/evaluation: /usr/local/lib/libopencv_imgproc.3.3.0.dylib
bin/evaluation: /usr/local/lib/libopencv_core.3.3.0.dylib
bin/evaluation: CMakeFiles/evaluation.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/carolineeche/Desktop/Massi/Traitement_image/tp1/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable bin/evaluation"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/evaluation.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/evaluation.dir/build: bin/evaluation

.PHONY : CMakeFiles/evaluation.dir/build

CMakeFiles/evaluation.dir/requires: CMakeFiles/evaluation.dir/evaluation.cpp.o.requires

.PHONY : CMakeFiles/evaluation.dir/requires

CMakeFiles/evaluation.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/evaluation.dir/cmake_clean.cmake
.PHONY : CMakeFiles/evaluation.dir/clean

CMakeFiles/evaluation.dir/depend:
	cd /Users/carolineeche/Desktop/Massi/Traitement_image/tp1 && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/carolineeche/Desktop/Massi/Traitement_image/tp1 /Users/carolineeche/Desktop/Massi/Traitement_image/tp1 /Users/carolineeche/Desktop/Massi/Traitement_image/tp1 /Users/carolineeche/Desktop/Massi/Traitement_image/tp1 /Users/carolineeche/Desktop/Massi/Traitement_image/tp1/CMakeFiles/evaluation.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/evaluation.dir/depend

