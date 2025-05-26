#!/usr/bin/bash

cppcheck --enable=all --quiet \
    --inline-suppr \
    --project="${BUILD_DIR:-build}"/compile_commands.json \
    -I "${BUILD_DIR:-build}/_deps/googletest-src/googletest/include" \
    -i"${BUILD_DIR:-build}" --suppress="*:${BUILD_DIR:-build}/*" \
    -i"${EXT_DIR:-ext}" --suppress="*:${EXT_DIR:-ext}/*" \
    -i"${GEN_DIR:-generated}" --suppress="*:${GEN_DIR:-generated}/*" \
    --suppress=missingIncludeSystem \
    --suppress=unmatchedSuppression \
    --suppress=useStlAlgorithm \
    --check-level=exhaustive \
