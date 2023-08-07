class FooBar {
private:
    int n;
    mutex mtx;
    condition_variable cv;
    bool fooflag;

public:
    FooBar(int n) {
        this->n = n;
        fooflag = true;
    }

    void foo(function<void()> printFoo) {
        
        for (int i = 0; i < n; i++) {
            
            unique_lock<mutex> lck(mtx);
            cv.wait(lck, [this](){return fooflag;});

        	// printFoo() outputs "foo". Do not change or remove this line.
        	printFoo();
            fooflag = false;
            cv.notify_one();
        }
    }

    void bar(function<void()> printBar) {
        
        for (int i = 0; i < n; i++) {
            unique_lock<mutex> lck(mtx);
            cv.wait(lck, [this](){return !fooflag;});
        	// printBar() outputs "bar". Do not change or remove this line.
        	printBar();

            fooflag = true;
            cv.notify_one();
        }
    }
};