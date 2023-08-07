class H2O {
public:
    H2O() {

    }


    int hydrogen_count = 0;
    int oxygen_count = 0;

    std::mutex hydrogen_mutex;
    std::mutex oxygen_mutex;

    void hydrogen(function<void()> releaseHydrogen) {
        hydrogen_mutex.lock();
        releaseHydrogen();
        hydrogen_count++;
        while (hydrogen_count > 2 * oxygen_count)
            this_thread::yield();
        hydrogen_mutex.unlock();
    }

    void oxygen(function<void()> releaseOxygen) {
        oxygen_mutex.lock();
        releaseOxygen();
        oxygen_count++;
        while (hydrogen_count < 2 * oxygen_count)
            this_thread::yield();
        oxygen_mutex.unlock();
    }
};