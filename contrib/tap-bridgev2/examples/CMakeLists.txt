
build_lib_example(
    NAME test-tapbridgev2-2container-my
    SOURCE_FILES test-tapbridgev2-2container-my.cc
    LIBRARIES_TO_LINK         ${libcsma}
      ${libtap-bridge}
      ${libinternet}
)
# build_lib_example(
#     NAME test-tapbr-csma-vr
#     SOURCE_FILES test-tapbr-csma-vr.cc
#     LIBRARIES_TO_LINK         ${libcsma}
#       ${libtap-bridge}
#       ${libinternet}
#       ${libtap-bridgev2}
# )
