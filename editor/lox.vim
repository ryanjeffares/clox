if exists('b:current_syntax)')
  finish
endif

syn keyword loxKeywords if for while print or and super this nil skipwhite
syn keyword loxBooleans true false skipwhite
syn keyword loxNamedKeywords var final fun class skipwhite
syn keyword loxTodo contained TODO
syn match loxComment "//.*$" contains=loxTodo

syn match loxNumber "\v<\d+>"
syn match loxNumber "\v<\d+\.\d+>"
syn region loxString start='"' end='"' oneline

let b:current_syntax = "lox"

hi def link loxTodo           Todo
hi def link loxComment        Comment
hi def link loxString         String
hi def link loxNumber         Number
hi def link loxBooleans       Boolean
hi def link loxKeywords       Keyword
hi def link loxNamedKeywords  Keyword
