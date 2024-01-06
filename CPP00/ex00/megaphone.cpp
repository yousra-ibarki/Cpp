#include <iostream>
int x;

int count_len(char **av)
{
    int i;

    i = 0;
    
    while(av[i])
        i++;
    return (i - 1);
}

int main(int ac, char **av)
{
    int i;
    int j;

    i = 0;
    if(ac == 1)
        std::cout << "RINGGGGG!!! RINGGGGG!!! 📞🔊💢";
    while(av[++i])
    {
        j = 0;
        while(av[i][j])
        {
            if(av[i][j] >= 'a' && av[i][j] <= 'z')
            {
                av[i][j] = (av[i][j] - 32);
                std::cout << av[i][j];
            }   
            else
                std::cout << av[i][j];
            j++;
        }
        if(av[i][j] != '\0')
            std::cout << " ";
    }

    return 0;
}