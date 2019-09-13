#include <iostream>
#include <vector>

void print_2d_vector(std::vector<std::vector<std::string>> color_vec_2d)
{
    for (unsigned int i=0; i<color_vec_2d.size(); i++)
    {
        for (unsigned int j=0; j<color_vec_2d.size(); j++)
        {
            std::cout << color_vec_2d.at(j).at(i) << " ";
        }
        std::cout << std::endl;
    }
}

int main(){
    
    
    std::vector<std::string> color_vec1{"blue","white"};
    std::vector<std::string> color_vec2{"green","white"};
    std::vector<std::string> color_vec3{"green","white"};

    std:: string missing_1, missing_2, missing_3;
    
    std::cout<<"Enter the 3 missing peg colors based on the picture of the tray:"<<std::endl;
    std::cin>> missing_1>>missing_2>>missing_3;
    
    color_vec1.push_back(missing_1);
    color_vec2.insert(color_vec2.begin(),missing_2);
    color_vec3.insert(color_vec3.begin()+1,missing_3);
    
    std::vector<std::vector<std::string>> color_vec2D{color_vec1,color_vec2,color_vec3};;
    
    print_2d_vector(color_vec2D);
    
    return 0;
}

    

