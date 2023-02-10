public class Playlist extends ContentCollection{
  public Playlist(){
    super();
  }
  public Playlist(String title){
    super(title);
  }
  //add and remove method
  public void addContent(Content a) {
    m_ContentList.add(a);
  }
  public void removeContent(int r) {
    m_ContentList.remove(r);
  }
}
