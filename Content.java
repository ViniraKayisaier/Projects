public abstract class Content{
  protected String m_title;
  protected String m_artist;
  protected int m_numofStreaming;

  //default
  public Content(){
    m_title = "";
    m_artist = "";
    m_numofStreaming = 0;
  }
  //fully specified
  public Content(String title, String artist){
    m_title = title;
    m_artist = artist;
    m_numofStreaming = 0;

  }
  //stream method
  public void Stream(){
    m_numofStreaming++;
    System.out.println(m_title + "by"+ m_artist+"is now streaming.");
  }
  // compareTo method
   public Content(Content p){
    this.m_numofStreaming = p.m_numofStreaming;
  }
}
