boomLine (x, y) =
  let res = x - y
  in "#define SUB_BOOM_" ++ (show x) ++ "_" ++ (show y) ++ "\t"
     ++ (if res < 0 then "~" else show res)

main = do
  let ls = map boomLine $ (,) <$> [0 .. BOOM_LIMIT] <*> [0 .. BOOM_LIMIT]
  mapM_ putStrLn ls
