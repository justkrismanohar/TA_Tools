

public interface Device{
    String getID();
    boolean isBreezy();
    boolean isNoisy();
    void turnOn();
    void turnOff();
    int coolsBy();
    
    boolean isOn();
    int getBreeziness();
    int getNoisiness();
}
