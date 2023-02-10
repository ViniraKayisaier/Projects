public class Podcasts extends Content{
  private int m_episode;

  public Podcasts(){
    super();
    int m_episode = 1;
  }
  //default
  public Podcasts(String title, String artist,int episode){
    super(title,artist);
    m_episode = episode;
  }
  //accessor
  public int getEpisode(){
    return m_episode;
  }

}
