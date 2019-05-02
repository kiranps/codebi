[@react.component]
let make = () =>
  <AppContext.Provider>
    <EditorContainer> <Editor /> </EditorContainer>
    <PreviewContainer> <Preview /> </PreviewContainer>
  </AppContext.Provider>;