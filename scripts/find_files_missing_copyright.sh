#!/bin/bash

find . -name "*.cpp" -exec ./scripts/print_if_no_copyright.sh {} \;
find . -name "*.hpp" -exec ./scripts/print_if_no_copyright.sh {} \;
