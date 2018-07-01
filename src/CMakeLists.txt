
add_executable(1000_test ./1000/main.cpp)
add_test(1000_test_1 1000_test)


#file(GLOB children RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} ${CMAKE_CURRENT_SOURCE_DIR}/*)

#FOREACH(child ${children})
#    IF (IS_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/${child})
        #message(FATAL_ERROR, ${CMAKE_CURRENT_SOURCE_DIR}/${child})
 #       add_executable(tttest ./${child}/main.cpp)
        #install(TARGETS ${child} RUNTIME DESTINATION bin)
  #      add_test(${child}_test tttest --output output )
        #ADD_TEST(MyTestCreateCompare ${CMAKE_COMMAND} -E compare_files output output)    
   # ENDIF()
#ENDFOREACH()
  

#FOREACH(subdir ${SUBDIRS})
#    
#    add_executable(${subdir} ./${subdir}/main.cpp)
 #   add_test(${subdir}_test ${subdir})

#ENDFOREACH()
