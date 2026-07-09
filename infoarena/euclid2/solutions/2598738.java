fun main() {
    val n = readLine()!!.toLong()
    for (i in 1..n) {
        var (a, b) = readLine()!!.split(' ').map { it.toLong() }
        if (b > a) {
            a = b.also { b = a }
        }
        var cmmdc = 1
        while (b != 0L) {
            a = b.also { b = a % b }
        }
        println(a)
    }
}