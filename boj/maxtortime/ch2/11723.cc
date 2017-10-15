#include <cstdio>
#include <vector>

int main() {
    unsigned int m = 0;
    bool set[20];
    std::vector<bool> result;
    
    scanf("%d", &m);

    for (int i = 0; i < m ; i++) {
        char cmd[10];
        int x;
        scanf("%s%d", cmd, &x);
        
        // add
        if (cmd[1] == 'd') {
            set[x-1] = true;
        }
        // check
        else if (cmd[1] == 'h') {
            printf("%d\n", set[x-1]);
        }
        // remove
        else if (cmd[1] == 'e') {
            set[x-1] = false;
        }
        // toggle
        else if (cmd[1] == 'o') {
            set[x-1] = set[x-1] ? false : true;
        }
        // all
        else if (cmd[1] == 'l') {
            for (int i = 0; i < 20 ; i++) set[i] = true;
        }
        // empty
        else if (cmd[1] == 'm') {
            for (int i = 0; i < 20 ; i++) set[i] = false;
        }
    }
}
