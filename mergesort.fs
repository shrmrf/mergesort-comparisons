
let rec mergesort (xs: list<int>) =
    let rec merge (xs: list<int>, ys: list<int>) =
        match (xs, ys) with
            | ([], ys) -> ys
            | (xs, []) -> xs
            | (x::xs1, y::ys1) -> 
                if(x < y) then x::merge(xs1, ys) 
                else y::merge(xs, ys1)
    let n = xs.Length / 2
    if (n = 0) then xs
    else
        let left, right = List.splitAt n xs
        merge (mergesort left, mergesort right)

mergesort [100;9;2;13]