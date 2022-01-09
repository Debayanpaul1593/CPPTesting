/**
 * Hashtable with open addressing
 * linear probing
*/
#include <iostream>
using namespace std;

template <typename K, typename V>
class HashNode
{
public:
    V value;
    K key;

    //constructor
    HashNode(K key, V value)
    {
        this->key = key;
        this->value = value;
    }
};
template <typename K, typename V>
class HashMap
{
    HashNode<K, V> **arr;
    int capacity;
    int size;
    HashNode<K, V> *dummy;

public:
    HashMap();
    int getHashCode(K key);
    void insertNode(K key, V val);
    void deleteNode(K key);
    V get(K key);
    bool isEmpty();
    int getMapSize();
    void display();
};
template <typename K, typename V>
bool HashMap<K, V>::isEmpty()
{
    return size == 0;
}

template <typename K, typename V>
int HashMap<K, V>::getMapSize()
{
    return size;
}

template <typename K, typename V>
HashMap<K, V>::HashMap()
{
    size = 0;
    capacity = 20;
    arr = new HashNode<K, V> *[capacity];
    for (int i = 0; i < capacity; i++)
    {
        arr[i] = NULL;
    }
    dummy = new HashNode<K, V>(-1, -1);
}

template <typename K, typename V>
void HashMap<K, V>::insertNode(K key, V val)
{
    HashNode<K, V> *temp = new HashNode<K, V>(key, val);
    int index = getHashCode(key);
    if (arr[index] == NULL)
    {
        arr[index] = temp;
        size++;
    }
    else
    {
        for (int i = 0; i < capacity; i++)
        {
            if (arr[i] == NULL)
            {
                arr[i] = temp;
                size++;
                break;
            }
        }
    }
}

template <typename K, typename V>
void HashMap<K, V>::deleteNode(K key)
{
    for (int i = 0; i < capacity; i++)
    {
        if (arr[i] != NULL && arr[i]->key == key)
        {
            arr[i] = NULL;
        }
    }
}

template <typename K, typename V>
int HashMap<K, V>::getHashCode(K key)
{
    return key % capacity;
}

template <typename K, typename V>
V HashMap<K, V>::get(K key)
{
    int hashCode = getHashCode(key);
    return arr[hashCode]->value;
}

template <typename K, typename V>
void HashMap<K, V>::display()
{
    cout << "{" << endl;
    for (int i = 0; i < capacity; i++)
    {
        HashNode<K, V> *temp = arr[i];
        if (temp != NULL)
            cout << "  " << temp->key << " : " << temp->value << ", \n";
    }
    cout << "}" << endl;
}

int main()
{
    HashMap<int, int> map;
    map.insertNode(5, 9);
    map.insertNode(6, 13);
    map.insertNode(26, 44);
    map.deleteNode(5);
    map.insertNode(1, 71);
    map.insertNode(7, 81);
    map.insertNode(9, 67);
    map.display();
    cout << "size: " << map.getMapSize() << endl;
    cout << "4th element: " << map.get(7) << endl;
    return 0;
}