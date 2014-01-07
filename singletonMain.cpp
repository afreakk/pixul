#include <iostream>

template <class T>
class Singleton
{
public:
  template <typename... Args>
  static
  T* get_instance(Args... args)
  {
    if (!instance_)
      {
        instance_ = new T(std::forward<Args>(args)...);
      }

    return instance_;
  }

  static
  void destroy_instance()
  {
    delete instance_;
    instance_ = nullptr;
  }

private:
  static T* instance_;
};

template <class T> T*  Singleton<T>::instance_ = nullptr;

using namespace std;
class Map: public Singleton<Map>
{
  friend class Singleton<Map>;
private:
  Map(int size_x, int size_y): size_x_{size_x}, size_y_{size_y} {cout << "wtupmain"<<endl;}

public:
  int size_x_;
  int size_y_;
};

class MapX: public Singleton<MapX>
{
  friend class Singleton<MapX>;
private:
  MapX(int size_x, int size_y): size_x_{size_x}, size_y_{size_y} {cout << "wtupmainXXXX"<<endl;}

public:
  int size_x_;
  int size_y_;
};

int main()
{
  Map* m = Map::get_instance(4, 5);
  MapX * mx = MapX::get_instance(1,1);

  std::cout << Map::get_instance()->size_y_ << std::endl; // Outputs 5.
  MapX::destroy_instance();
  Map::destroy_instance();
}
