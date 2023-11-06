#include "PmergeMe.hpp"

template<typename T, typename S, typename V>
void sort(int argc, char *argv[], T &container, S &conta, V &contb, std::string choice, bool flag, int tmp, bool print) {
    struct timeval start, end; 
    long sec, microsec;
    (void) argv;

    gettimeofday(&start, NULL);
    for(size_t i = 0; i < container.size(); i++) {
        if (container[i].first > container[i].second)
            std::swap(container[i].first, container[i].second);
    }
    for(size_t i = 0; i < container.size(); i++) {
        conta.push_back(container[i].first);
    }
    for(size_t i = 0; i < container.size(); i++) {
        contb.push_back(container[i].second);
    }
    std::sort(conta.begin(), conta.end());

    for (size_t i = 0; i < contb.size(); i++)
        conta.insert(std::lower_bound(conta.begin(), conta.end(), contb[i]), contb[i]);
    if (flag)
        conta.insert(std::lower_bound(conta.begin(), conta.end(), tmp), tmp);
    if(print) {
        std::cout << "\nAfter : ";
        for (size_t i = 0; i < conta.size(); i++) {
            std::cout << conta[i] << " ";
            if (i == 5 && conta.size() > 6) {
                std::cout << "[...]";
                break;
            }
                
        }
        std::cout << std::endl;
            
    }
    gettimeofday(&end, NULL);
    sec = end.tv_sec - start.tv_sec;
    microsec = end.tv_usec - start.tv_usec;
    long diff = (sec / 1000000) + (microsec);
    std::cout << "Time to process a range of " << argc << " elements with " << choice << " : " << diff  << " us";
    std::cout << std::endl;
}

int checkInputValid(const char *input) {
    std::istringstream ss(input);
    int nb;
    ss >> nb;

    if (ss.fail() || !ss.eof()) {
        return -1;
    }

    if (nb < 0) {
        return -1;
    }

    return nb;
}

void checkInput(int argc, char **argv, bool flag, std::string choice, int tmp) {
    std::vector<std::pair<unsigned int, unsigned int> > _vector;
    std::deque<std::pair<unsigned int, unsigned int> > _list;
    int i = 1;
    int tämp;
    while (argv[i]) {
        try {
            int nb = checkInputValid(argv[i]);
            if (nb == -1) 
                throw InvalidInputException();
            else
                if (i % 2 == 0) {
                    std::pair<unsigned int, unsigned int>newPair(nb, tämp);
                    _vector.push_back(newPair);
                    _list.push_back(newPair);
                }    
                else
                    tämp = nb;
                i++;
        }
        catch(std::exception &e) {
            std::cout << e.what() << std::endl;
            exit(0);
        }
    }
    if (choice == "std::vector") {
        std::vector<unsigned int> _vectora, _vectorb;
        sort(argc, argv, _vector, _vectora, _vectorb, "std::vector", flag, tmp, true);
    }
    if (choice == "std::deque") {
        std::deque<unsigned> _lista, _listb;
        sort(argc, argv, _list, _lista, _listb, "std::deque", flag, tmp, false);
    }
}

