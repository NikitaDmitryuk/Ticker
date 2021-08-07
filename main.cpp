#include "AvrControl.h"

int main() {
    int8_t array[64] =
            {0, 0, 0, 1, 1, 0, 0, 0,
             0, 0, 0, 1, 1, 0, 0, 0,
             0, 0, 0, 1, 1, 0, 0, 0,
             0, 0, 0, 1, 1, 0, 0, 0,
             0, 0, 0, 1, 1, 0, 0, 0,
             0, 0, 0, 1, 1, 0, 0, 0,
             0, 1, 1, 1, 1, 1, 1, 0,
             0, 1, 1, 1, 1, 1, 1, 0};

    AvrControl avrcontrol = AvrControl();
    avrcontrol.display(array, 10.0);
    return 0;
}
