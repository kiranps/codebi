[@react.component]
let make = (~docId) =>
  <PlayGroundContext.Provider>
    <EditorContainer> <Editor docId /> </EditorContainer>
    <PreviewContainer> <Preview /> </PreviewContainer>
  </PlayGroundContext.Provider>;