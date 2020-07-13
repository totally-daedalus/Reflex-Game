# include "ConsoleGameEngine.h"

class Game : public ConsoleGameEngine {
    int x = 2;
    int y = 1;
    int spaces = 2;
    int middlespaces = 2;
    int score = 0;

    int maxwaitbeforepenalty = 2500;

    int penalty = 25;
    
    long times[8];
    bool color[8];

    std::vector<int> index;
    std::vector<int> time;
    
    int get_score(int i) {
        for(int j = 0; j < index.size(); j++) {
            if(j == i) {
                int score = get_current_time() - time[j];
                index.erase(index.begin() + j);
                time.erase(time.begin() + j);
                return (maxwaitbeforepenalty - score) / 100;
            }
        }

        return 0;
    }

    void draw_guide() {
        draw(x, y, "#", get_pair(color[0] + 1));
        draw(x, y + 1, "a");
        draw(x + spaces * 1, y, "#", get_pair(color[1] + 1));
        draw(x + spaces * 1, y + 1, "s");
        draw(x + spaces * 2, y, "#", get_pair(color[2] + 1));
        draw(x + spaces * 2, y + 1, "d");
        draw(x + spaces * 3, y, "#", get_pair(color[3] + 1));
        draw(x + spaces * 3, y + 1, "f");
         
        draw(x + spaces * 4 + middlespaces, y, "#", get_pair(color[4] + 1));
        draw(x + spaces * 4 + middlespaces, y + 1, "j");
        draw(x + spaces * 5 + middlespaces, y, "#", get_pair(color[5] + 1));
        draw(x + spaces * 5 + middlespaces, y + 1, "k");
        draw(x + spaces * 6 + middlespaces, y, "#", get_pair(color[6] + 1));
        draw(x + spaces * 6 + middlespaces, y + 1, "l"); 
        draw(x + spaces * 7 + middlespaces, y, "#", get_pair(color[7] + 1));
        draw(x + spaces * 7 + middlespaces, y + 1, ";");
    }

    void update_events() {
        for(int i = 0; i < 8; i++) {
            if(get_current_time() >= times[i]) {
                if(color[i]) {
                    color[i] = false;
                    index.push_back(i);
                    time.push_back(get_current_time());
                }
            } else {
                color[i] = true;
            }
        }

        if(get_key('a')) {
            if(!color[0]) {
                times[0] = get_current_time() + rand() % 3000 + 1000;
                score += get_score(0);
            } else {
                score -= penalty;
            }
        } if(get_key('s')) {
            if(!color[1]) {
                times[1] = get_current_time() + rand() % 3000 + 1000;
                score += get_score(1);
            } else {
                score -= penalty;
            }
        } if(get_key('d')) {
            if(!color[2]) {
                times[2] = get_current_time() + rand() % 3000 + 1000;
                score += get_score(2);
            } else {
                score -= penalty;
            }
        } if(get_key('f')) {
            if(!color[3]) {
                times[3] = get_current_time() + rand() % 3000 + 1000;
                score += get_score(3);
            } else {
                score -= penalty;
            }
        }

        if(get_key('j')) {
            if(!color[4]) {
                times[4] = get_current_time() + rand() % 3000 + 1000;
                score += get_score(4);
            } else {
                score -= penalty;
            }
        } if(get_key('k')) {
            if(!color[5]) {
                times[5] = get_current_time() + rand() % 3000 + 1000;
                score += get_score(5);
            } else {
                score -= penalty;
            }
        } if(get_key('l')) {
            if(!color[6]) {
                times[6] = get_current_time() + rand() % 3000 + 1000;
                score += get_score(6);
            } else {
                score -= penalty;
            }
        } if(get_key(';')) {
            if(!color[7]) {
                times[7] = get_current_time() + rand() % 3000 + 1000;
                score += get_score(7);
            } else {
                score -= penalty;
            }
        }

        if(get_key(K_ESCAPE)) {
            close(std::to_string(score));
        }
    }

    virtual void start() {
        create_pair(1, RED, BLACK);
        create_pair(2, GREEN, BLACK);

        for(int i = 0; i < 8; i++) {
            times[i] = get_current_time() + rand() % 3000 + 1000;
            color[i] = true;
        }
    }

    virtual void update() {
        update_events();
        draw_guide();

        draw(2, 4, std::to_string(score) + " esc: quit");

        flush();
        clear();
    }
};

int main() {
    Game game;
    game.construct_console(30, 10);
}
