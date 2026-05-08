cmake_minimum_required(VERSION 3.8)
project(test_pkg)

find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(GTest REQUIRED)

# Mimic your "roseybot" structure
file(GLOB TEST_SOURCES 
  "test/software/*.cpp"
  "test/hardware/*.cpp"
)

foreach(test_source ${TEST_SOURCES})
    get_filename_component(BASE_NAME ${test_source} NAME_WE)
    get_filename_component(PARENT_DIR ${test_source} DIRECTORY)
    get_filename_component(FOLDER_NAME ${PARENT_DIR} NAME)

    set(TARGET_NAME "${FOLDER_NAME}_${BASE_NAME}")

    add_executable(${TARGET_NAME} ${test_source})
    target_link_libraries(${TARGET_NAME} GTest::gtest_main rclcpp::rclcpp)
    add_test(NAME ${TARGET_NAME} COMMAND ${TARGET_NAME})
endforeach()

ament_package()