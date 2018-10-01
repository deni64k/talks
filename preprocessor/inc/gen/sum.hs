boomLine (x, y) = "#define SUM_BOOM_" ++ (show x) ++ "_" ++ (show y) ++ "\t"
                ++ (show $ x + y)

main = do
  let ls = map boomLine $ (,) <$> [0 .. BOOM_LIMIT] <*> [0 .. BOOM_LIMIT]
  mapM_ putStrLn ls
