module mainModule
[<EntryPoint>]
let main argv =
    let s1 = "aabbcc"
    let s2 = "aabbcc"

    LCS.lcs_parallel s1 s2 8 |> printfn "%s"
    0 // return an integer exit code
