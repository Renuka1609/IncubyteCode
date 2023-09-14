#include <iostream>
#include <vector>

class GalacticSpaceCraft {
public:
    GalacticSpaceCraft(int x, int y, int z, char initialDirection, char initialDirection1)
        : x_(x), y_(y), z_(z), direction_(initialDirection), direction1_(initialDirection1) {}
//For moving forward we check the direction and move according one step at a time
    void moveForward() {
        switch (direction_) {
            case 'N':
                y_++;
                break;
            case 'S':
                y_--;
                break;
            case 'E':
                x_++;
                break;
            case 'W':
                x_--;
                break;
            case 'U':
                z_++;
                break;
            case 'D':
                z_--;
                break;
        }
    }
//For moving Backward we check the direction and move according one step at a time
    void moveBackward() {
        switch (direction_) {
            case 'N':
                y_--;
                break;
            case 'S':
                y_++;
                break;
            case 'E':
                x_--;
                break;
            case 'W':
                x_++;
                break;
            case 'U':
                z_--;
                break;
            case 'D':
                z_++;
                break;
        }
    }
    //We rotate by 90 degree to left by checking the current direction
    void turnLeft() {
        switch (direction_) {
            case 'N':
                direction_ = 'W';
                direction1_ = 'W';
                break;
            case 'S':
                direction_ = 'E';
                direction1_ = 'E';
                break;
            case 'E':
                direction_ = 'N';
                direction1_ = 'N';
                break;
            case 'W':
                direction_ = 'S';
                direction1_ = 'S';
                break;
            case 'U':
                switch (direction1_) {
                    case 'N':
                        direction_ = 'W';
                        direction1_ = 'W';
                        break;
                    case 'S':
                        direction_ = 'E';
                        direction1_ = 'E';
                        break;
                    case 'E':
                        direction_ = 'N';
                        direction1_ = 'N';
                        break;
                    case 'W':
                        direction_ = 'S';
                        direction1_ = 'S';
                        break;
                }
                break; // Add a break statement here
            case 'D':
                switch (direction1_) {
                    case 'N':
                        direction_ = 'W';
                        direction1_ = 'W';
                        break;
                    case 'S':
                        direction_ = 'E';
                        direction1_ = 'E';
                        break;
                    case 'E':
                        direction_ = 'N';
                        direction1_ = 'N';
                        break;
                    case 'W':
                        direction_ = 'S';
                        direction1_ = 'S';
                        break;
                }
                break; // Add a break statement here
        }
    }

    void turnRight() {
        switch (direction_) {
            case 'N':
                direction_ = 'E';
                direction1_ = 'E';
                break;
            case 'S':
                direction_ = 'W';
                direction1_ = 'W';
                break;
            case 'E':
                direction_ = 'S';
                direction1_ = 'S';
                break;
            case 'W':
                direction_ = 'N';
                direction1_ = 'N';
                break;
            case 'U':
                switch (direction1_) {
                    case 'N':
                        direction_ = 'E';
                        direction1_ = 'E';
                        break;
                    case 'S':
                        direction_ = 'W';
                        direction1_ = 'W';
                        break;
                    case 'E':
                        direction_ = 'S';
                        direction1_ = 'S';
                        break;
                    case 'W':
                        direction_ = 'N';
                        direction1_ = 'N';
                        break;
                }
                break; // Add a break statement here
            case 'D':
                switch (direction1_) {
                    case 'N':
                        direction_ = 'E';
                        direction1_ = 'E';
                        break;
                    case 'S':
                        direction_ = 'W';
                        direction1_ = 'W';
                        break;
                    case 'E':
                        direction_ = 'S';
                        direction1_ = 'S';
                        break;
                    case 'W':
                        direction_ = 'N';
                        direction1_ = 'N';
                        break;
                }
                break; // Add a break statement here
        }
    }

    void turnUp() {
        if (direction_ != 'U') {
            direction_ = 'U';
        }
    }

    void turnDown() {
        if (direction_ != 'D') {
            direction_ = 'D';
        }
    }

    void executeCommands(const std::vector<char>& commands) {
        for (char cmd : commands) {
            switch (cmd) {
                case 'f':
                    moveForward();
                    break;
                case 'b':
                    moveBackward();
                    break;
                case 'l':
                    turnLeft();
                    break;
                case 'r':
                    turnRight();
                    break;
                case 'u':
                    turnUp();
                    break;
                case 'd':
                    turnDown();
                    break;
            }
        }
    }

    void getCurrentPosition(int& x, int& y, int& z) const {
        x = x_;
        y = y_;
        z = z_;
    }

    char getCurrentDirection() const {
        return direction_;
    }

private:
    int x_, y_, z_;
    char direction_;
// MAINTAINED DIRECTION 1 TO STORE THE NORMAL DIRECTION BEFORE UP OR DOWN MOVEMENT SO THAT RIGHT AND LEFT TURNS WILL BE RECORDED ACCORDINGLY
    char direction1_;
};

int main() {
    GalacticSpaceCraft spacecraft(0, 0, 0, 'N', 'N');

    std::vector<char> commands = {'f', 'r', 'u', 'b', 'l'};

    spacecraft.executeCommands(commands);

    int finalX, finalY, finalZ;
    char finalDirection;
    spacecraft.getCurrentPosition(finalX, finalY, finalZ);
    finalDirection = spacecraft.getCurrentDirection();

    std::cout << "Final Position: (" << finalX << ", " << finalY << ", " << finalZ << ")\n";
    std::cout << "Final Direction: " << finalDirection << "\n";

    return 0;
}
