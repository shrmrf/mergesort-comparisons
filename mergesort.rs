/*
  bad implementation I guess because this is my first attempt
  at writing any rust 
*/
fn merge_split(l1: &mut Vec<i32>) {
    // println!("len: {}, list: {:?}", l1.len(), l1);
    if l1.len() <= 1{
        return;
    }
    else {
        let mid: usize = l1.len() / 2;
        let mut left = l1[0 .. mid].to_vec();
        let mut right = l1[mid .. l1.len()].to_vec();
        merge_split(&mut left);
        merge_split(&mut right);
        
        let mut i: usize = 0;
        let mut j: usize = 0;
        let mut k: usize = 0;

        while (i < left.len()) && (j < right.len()) {
            if left[i] < right[j] {
                l1[k] = left[i];
                i = i + 1;
            } else {
                l1[k] = right[j];
                j = j + 1;
            }
            k = k + 1;
        }
        while i < left.len() {
            l1[k] = left[i];
            i = i + 1;
            k = k + 1;
        }
        while j < right.len() {
            l1[k] = right[j];
            j = j + 1;
            k = k + 1;
        }
    }
}

pub fn mergesort(l1: &mut Vec<i32>) {
  merge_split(l1);
}

fn main () {
    fn fact(x: u32) -> u32 { if x==0 {1} else {x * fact(x - 1)} }
    println!("{}", fact(5));


    // Example mutable vector of i32 elements
    let mut example_list: Vec<i32> = vec![234234, 9, 4, 5, 99, 1,-3, 0, -1];

    // Print the original vector to STDOUT
    println!("Original list: {:?}", example_list);

    // Merge the list
    mergesort(&mut example_list);

    // Print the sorted vector to STDOUT
    println!("Sorted list: {:?}", example_list);
}
