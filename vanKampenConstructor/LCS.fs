module LCS
  
  open System.Text
  open System.Runtime.InteropServices 
  
  module private Imported = 
    [<DllImport("../../lcs_omp.so", CallingConvention = CallingConvention.Cdecl)>]
    extern void LongestCommonSubstring(string c1, string c2, int threads, StringBuilder lcs)

  let lcs_parallel s1 s2 nthread =
    let lcs = new StringBuilder()
    Imported.LongestCommonSubstring(s1, s2, nthread, lcs)
    lcs.ToString()