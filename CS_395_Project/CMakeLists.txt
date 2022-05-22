set(HEADER_FILES
	Entity.h
	SpringApp.h
)

set(SOURCE_FILES
	Entity.cpp
	SpringApp.cpp
	main.cpp
)
	

add_executable(CS_395_Project ${HEADER_FILES} ${SOURCE_FILES})

include_directories(../Moth)

target_link_libraries(CS_395_Project Moth)

file(COPY Assets DESTINATION ${PROJECT_BINARY_DIR}/CS_395_Project)
file(COPY Assets DESTINATION ${PROJECT_BINARY_DIR}/Debug)
file(COPY Assets DESTINATION ${PROJECT_BINARY_DIR}/Release)