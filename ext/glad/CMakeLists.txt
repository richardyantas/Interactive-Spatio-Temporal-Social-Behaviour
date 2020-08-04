

#include_directories( ${ENV_INCLUDE_DIRECTORIES} )

include_directories(

    include

)

add_library(glad 
          src/glad.c
)