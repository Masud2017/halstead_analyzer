if(EXISTS "/mnt/e/intellijproject/c_cpp_codes/halstead_matrics_analyzer/build/halstead_analyzer[1]_tests.cmake")
  include("/mnt/e/intellijproject/c_cpp_codes/halstead_matrics_analyzer/build/halstead_analyzer[1]_tests.cmake")
else()
  add_test(halstead_analyzer_NOT_BUILT halstead_analyzer_NOT_BUILT)
endif()
