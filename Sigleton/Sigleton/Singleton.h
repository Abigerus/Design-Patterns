class Singleton
{
private:
	static Singleton * p_instance;
	// Constructors and assignment operator aren't available to clients
	Singleton() {}
	Singleton(const Singleton&);
	Singleton& operator=(Singleton&);
public:
	static Singleton * getInstance() {
		if (!p_instance)
			p_instance = new Singleton();
		return p_instance;
	}

};