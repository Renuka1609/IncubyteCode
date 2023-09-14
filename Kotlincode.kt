class Spacecraft {
    var x = 0
    var y = 0
    var z = 0
    var direction = "N"

    fun moveForward() {
        when (direction) {
            "N" -> y++
            "S" -> y--
            "E" -> x++
            "W" -> x--
            "U" -> z++
            "D" -> z--
        }
    }

    fun moveBackward() {
        when (direction) {
            "N" -> y--
            "S" -> y++
            "E" -> x--
            "W" -> x++
            "U" -> z--
            "D" -> z++
        }
    }

    fun turnLeft() {
        direction = when (direction) {
            "N" -> "W"
            "S" -> "E"
            "E" -> "N"
            "W" -> "S"
            "U" -> "N"
            "D" -> "S"
            else -> direction
        }
    }

    fun turnRight() {
        direction = when (direction) {
            "N" -> "E"
            "S" -> "W"
            "E" -> "S"
            "W" -> "N"
            "U" -> "N"
            "D" -> "S"
            else -> direction
        }
    }

    fun turnUp() {
        direction = when (direction) {
            "N" -> "U"
            "S" -> "D"
            "E" -> "U"
            "W" -> "D"
            else -> direction
        }
    }

    fun turnDown() {
        direction = when (direction) {
            "N" -> "D"
            "S" -> "U"
            "E" -> "D"
            "W" -> "U"
            else -> direction
        }
    }

    fun processCommands(commands: List<String>) {
        for (command in commands) {
            when (command) {
                "f" -> moveForward()
                "b" -> moveBackward()
                "l" -> turnLeft()
                "r" -> turnRight()
                "u" -> turnUp()
                "d" -> turnDown()
            }
        }
    }

    fun getPosition(): Triple<Int, Int, Int> = Triple(x, y, z)

    fun getDirection(): String = direction
}

fun main() {
    val spacecraft = Spacecraft()
    val commands = listOf("f", "r", "u", "b", "l")
    spacecraft.processCommands(commands)
    val finalPosition = spacecraft.getPosition()
    val finalDirection = spacecraft.getDirection()
    println("Final Position: $finalPosition")
    println("Final Direction: $finalDirection")
}