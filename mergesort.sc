import scala.util.Random

def mergesort(xs: List[Int]): List[Int] = {
  def merge(xs: List[Int], ys: List[Int]): List[Int] = {
    (xs, ys) match {
      case (Nil, ys) => ys
      case (xs, Nil) => xs
      case (x::xs1, y::ys1) =>
        if (x < y) x::merge(xs1, ys)
        else y::merge(xs, ys1)
    }
  }
  val n = xs.length / 2
  if(n==0) {
    xs
  } else {

    val (left, right) = xs splitAt(n)
    merge(mergesort(left), mergesort(right))
  }
}

mergesort(List.fill(10)(Random.nextInt(500)))
