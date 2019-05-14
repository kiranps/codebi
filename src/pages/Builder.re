[@react.component]
let make = (~docId) =>
  <AppContext.Provider>
    <EditorContainer> <Editor docId /> </EditorContainer>
    <PreviewContainer> <Preview /> </PreviewContainer>
  </AppContext.Provider>;