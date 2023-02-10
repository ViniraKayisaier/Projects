import java.util.LinkedList;

public class Game {
    private Dealer dealer;
    private LinkedList<Player> players;
    private int Spoons;

    public Game(Dealer dealer, LinkedList<Player> players, int Spoons) {
        this.dealer = dealer;
        this.players = players;
        this.Spoons = Spoons;
    }
    // checking the spoons
    public void play() {
        while (Spoons > 0) {
            Spoons--;
        }
        if(Spoons == 0){
          boolean m_GameOver = true;
        }
    }
    //accessors
    public Dealer getDealer() {
        return dealer;
    }

    public LinkedList<Player> getPlayers() {
        return players;
    }

    public int getSpoons() {
        return Spoons;
    }
}
