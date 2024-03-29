file(REMOVE_RECURSE
  "libFramework.a"
  "libFramework.pdb"
)

# Per-language clean rules from dependency scanning.
foreach(lang CXX)
  include(CMakeFiles/Framework.dir/cmake_clean_${lang}.cmake OPTIONAL)
endforeach()
