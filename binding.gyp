{
    "targets": [
        {
            "target_name": "AnitomyNode",
            "cflags_cc": [ "-std=c++11" ],
            "sources": [
                    "src/Common.h",
                    "src/AnitomyNode.h",
                    "src/AnitomyNode.cc",
                    "src/Init.cc",
                    "libs/anitomy/anitomy/anitomy.cpp",
                    "libs/anitomy/anitomy/anitomy.h",
                    "libs/anitomy/anitomy/element.cpp",
                    "libs/anitomy/anitomy/element.h",
                    "libs/anitomy/anitomy/keyword.cpp",
                    "libs/anitomy/anitomy/keyword.h",
                    "libs/anitomy/anitomy/options.h",
                    "libs/anitomy/anitomy/parser.cpp",
                    "libs/anitomy/anitomy/parser.h",
                    "libs/anitomy/anitomy/parser_helper.cpp",
                    "libs/anitomy/anitomy/parser_number.cpp",
                    "libs/anitomy/anitomy/string.cpp",
                    "libs/anitomy/anitomy/string.h",
                    "libs/anitomy/anitomy/token.cpp",
                    "libs/anitomy/anitomy/token.h",
                    "libs/anitomy/anitomy/tokenizer.cpp",
                    "libs/anitomy/anitomy/tokenizer.h"
            ],
            "cflags": [
                "-std=c++11"
            ],
            "defines!":[
                '_HAS_EXPECTIONS=0'
            ],
            "variables":{
                "CURRENT_DIR":"<!(echo %~dp0)"
            },
            "include_dirs": [
                "<!(node -e \"require('nan')\")",
                "libs/anitomy"
            ]
        }
    ]
}
